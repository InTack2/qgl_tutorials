#ifndef QGL_TUTORIAL02_H
#define QGL_TUTORIAL02_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>

class Tutorial02 : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  explicit Tutorial02(QWidget* parent = 0);
  ~Tutorial02() override;

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void keyPressEvent(QKeyEvent* e) override;

 private:
  // https://doc.qt.io/qt-5/qopenglshaderprogram.html
  QOpenGLShaderProgram m_shaderProgram;
  GLuint m_vertexPosition_modelspaceID;
  GLuint m_vertexbuffer;
};

#endif  // QGL_TUTORIAL02_H
