#include <stdio.h>

extern const char build_host[];
extern const char build_scm_revision[];

int main() {
  printf("Built at sha: %s!\n", build_scm_revision);
  printf("Built with host: %s!\n", build_host);
  return 0;
}
