extern const char build_host[];
extern const char build_scm_revision[];

// Implicit and always available https://bazel.build/docs/user-manual#workspace-status
const char build_host[] = BUILD_HOST;
const char build_scm_revision[] = BUILD_SCM_REVISION;
