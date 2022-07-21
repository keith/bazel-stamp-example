#include <stdio.h>

extern const char build_scm_revision[];

int main() {
  printf("uilt at sha: %s!\n", build_scm_revision);
  return 0;
}
