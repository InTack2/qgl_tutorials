#include "qgl_tutorial02.h"

#include <QApplication>
#include <QKeyEvent>

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f,
    -1.0f,
    0.0f,
    1.0f,
    -1.0f,
    0.0f,
    0.0f,
    1.0f,
    0.0f,
};

/**
 * コンストラクタ
 */
Tutorial02::Tutorial02(QWidget* parent) : QOpenGLWidget(parent) {
  m_vertexPosition_modelspaceID = 0;
}

/**
 * デストラクタ
 */
Tutorial02::~Tutorial02() {
  glDeleteBuffers(1, &m_vertexbuffer);
}

/**
 * 初期化
 */
void Tutorial02::initializeGL() {
  // initialize OpenGL
  initializeOpenGLFunctions();

  // シェーダー読み込み
  // https://doc.qt.io/qt-5/qopenglshaderprogram.html#details
  shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/SimpleVertexShader.vert");
  shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/SimpleFragmentShader.frag");
  shaderProgram.link();

  // バッファ関連
  glGenBuffers(1, &m_vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, m_vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
  // GL_STATIC_DRAWは使用され方を指定

  GLuint programID = shaderProgram.programId();

  // https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetAttribLocation.xhtml
  // 指定したアトリビュートの位置を取得する？今回はmodelspaceの頂点位置か
  m_vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");

  glClearColor(0.0f, 0.0f, 0.3f, 0.0f);
}

void Tutorial02::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  shaderProgram.bind();

  GLuint programID = shaderProgram.programId();

  // Use our shader
  glUseProgram(programID);

  // 1rst attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, m_vertexbuffer);
  glVertexAttribPointer(m_vertexPosition_modelspaceID,  // The attribute we want to configure
                        3,                              // size
                        GL_FLAT,                        // type
                        GL_FALSE,                       // normalized?
                        0,                              // stride
                        (void*)0                        // array buffer offset
  );

  // Draw the triangle !
  glDrawArrays(GL_TRIANGLES, 0, 3);  // Starting from vertex 0; 3 vertices total -> 1 triangle

  glDisableVertexAttribArray(0);
}

void Tutorial02::resizeGL(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Tutorial02::keyPressEvent(QKeyEvent* e) {
  switch (e->key()) {
    case Qt::Key_Escape:
      exit(0);
      break;
    default:
      break;
  }
  e->accept();  // Don't pass any key events to parent
}

/**
 * Main Loop
 */
int main(int argc, char** argv) {
  QApplication a(argc, argv);

  Tutorial02 w;
  w.show();
  return a.exec();
}