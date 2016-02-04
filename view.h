// Protector
#ifndef __VIEWCLASS_H__
#define __VIEWCLASS_H__

// Includes
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include <QMouseEvent>
#include "logo.h"

// Definitions
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

// Class
class viewclass : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
    // Con/Des structor
    public:
    viewclass(QWidget *parent=0);
    ~viewclass();

    // Public
    public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void cleanup();

    // Protected
    protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    // Private
    private:
    void setupVertexAttribs();
    bool m_core;
    int m_xRot;
    int m_yRot;
    int m_zRot;
    QPoint m_lastPos;
    Logo m_logo;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_logoVbo;
    QOpenGLShaderProgram *m_program;
    int m_projMatrixLoc;
    int m_mvMatrixLoc;
    int m_normalMatrixLoc;
    int m_lightPosLoc;
    QMatrix4x4 m_proj;
    QMatrix4x4 m_camera;
    QMatrix4x4 m_world;
    bool    m_transparent;
};

#endif
