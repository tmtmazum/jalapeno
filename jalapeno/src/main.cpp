#include <QtWidgets>
#include <QtOpenGL>
#include <cstdio>

#define LOG(...) printf("[LOG] " __VA_ARGS__)
#define ASSERT(a) if(!(a)) printf("[ASSERT] " #a " actual:%d\n", a)

constexpr auto help = R"(
  Usage:

  ./%s 
)";

struct gl_widget_config
{
  QColor    clear_color = Qt::blue;

  QGLFormat format;
};

class gl_widget 
  : public QGLWidget
{
  gl_widget_config  m_cfg;

public:
  gl_widget()
  {
    setMinimumSize(800, 600);
  }

  void initializeGL() override
  {
    for (auto const feature : {GL_DEPTH_TEST, GL_CULL_FACE})
    {
      glEnable(feature);
    }

  }

  void paintGL() override
  {
    qglClearColor(m_cfg.clear_color);

    LOG("paintGL() completed.\n");
  }
};

void run_app(int argc, char** argv)
{
  QApplication app(argc, argv);
 
  QGridLayout* layout = new QGridLayout();
  layout->addWidget(new gl_widget());

  constexpr auto window_title = "Jalapeno";

  QWidget main_widget;
  main_widget.setLayout(layout);
  main_widget.setWindowTitle(window_title);

  main_widget.show();
  app.exec();
}

int main(int argc, char** argv)
{
  if (argc == 1)
  {
    run_app(argc, argv);
    return 0;
  }
  else
  {
    printf(help, argv[0]);
    return 1;
  }

  scanf("Press any key to exit..");
  printf("JOBS DONE\n");
  return 0;
}