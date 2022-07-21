#include <stdio.h>

extern const char build_scm_revision[];

int main() {
  printf("Built at sha: %s!\n", build_scm_revision);
  return 0;
}
