cc_binary(
    name = "main",
    srcs = [
        "main.c",
        "stamp.c",
    ],
)

genrule(
    name = "stamp_genrule",
    outs = ["stamp.c"],
    cmd = """
set -euo pipefail

build_scm_revision=$$(sed -n -E 's/^BUILD_SCM_REVISION ([0-9a-f]{40})$$/\\1/p' < bazel-out/volatile-status.txt)

echo "extern const char build_scm_revision[];" > $(OUTS)
echo "const char build_scm_revision[] = \\"$$build_scm_revision\\";" >> $(OUTS)
    """,
    # https://github.com/bazelbuild/bazel/issues/4942
    stamp = 1,
)
