#ifndef QGL_TUTORIAL01_H
#define QGL_TUTORIAL01_H

#include <QKeyEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

class Tutorial01 : public QOpenGLWidget, protected QOpenGLFunctions {
public:
  explicit Tutorial01(QWidget *parent = nullptr) : QOpenGLWidget(parent) {}

protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

  void keyPressEvent(QKeyEvent *e) override;
};

#endif // QGL_TUTORIAL01_H
