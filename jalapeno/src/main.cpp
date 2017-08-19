#include <QtWidgets>
#include <cstdio>

constexpr auto help = R"(
  Usage:

  ./%s 
)";

void run_app(int argc, char** argv)
{
  QApplication app(argc, argv);
  QWidget main_widget;
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