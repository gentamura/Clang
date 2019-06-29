#include <stdio.h>
#include <string.h>

char *p[] = {
  "err1",
  "err2"
};

void error(int err_num) {
  printf("%s\n", p[err_num]);
}

int main(void)
{
  error(1);

  return 0;
}
