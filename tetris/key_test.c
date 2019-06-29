#include <stdio.h>
#include <gconio.h>

int main() {
  int key;
  int flag = 1;

  while (flag) {
    if (kbhit()) {
      key = getch();
      if (key == 0 || key == 224) {
        key = getch();
      }
      flag = 0;
    }
  }

  switch(key) {
    case 0x4b:
      printf("Pushed left.\n");
      break;
    case 0x4d:
      printf("Pushed right.\n");
      break;
    default:
      printf("Pushed excpet left and right.\n");
      break;
  }

  return 0;
}
