# When targeting a binary, you can use this method without a genrule
cc_binary(
    name = "binary_example",
    srcs = ["main.c"],
    stamp = 1,
    deps = [":stamp_lib"],
)

cc_library(
    name = "stamp_lib",
    linkstamp = "linkstamp.cc",
)

# When targeting a library you cannot use the top level 'stamp = 1' attr so you have to use an approach like this with a genrule
cc_binary(
    name = "genrule_example",
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

build_host=$$(sed -n -E 's/^BUILD_HOST (.*)$$/\\1/p' < bazel-out/stable-status.txt)
build_scm_revision=$$(sed -n -E 's/^BUILD_SCM_REVISION ([0-9a-f]{40})$$/\\1/p' < bazel-out/volatile-status.txt)

if [[ -z "$$build_host" || -z "$$build_scm_revision" ]]; then
  echo "error: failed to fetch variables" >&2
  exit 1
fi

echo "extern const char build_host[];" > $(OUTS)
echo "extern const char build_scm_revision[];" >> $(OUTS)
echo "const char build_host[] = \\"$$build_host\\";" >> $(OUTS)
echo "const char build_scm_revision[] = \\"$$build_scm_revision\\";" >> $(OUTS)
    """,
    # https://github.com/bazelbuild/bazel/issues/4942
    stamp = 1,
)
