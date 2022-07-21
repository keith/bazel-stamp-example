# bazel-stamp-example

This is an example repo using bazel's under-documented "stamp" feature
to embed information into your final binary in a relatively safe way.

## Example

The `binary_example` target in the root [root `BUILD` file](BUILD) is
the standard example of linkstamps where you have a `cc_library` with
the `linkstamp` attribute, and depend on that from a binary that sets
`stamp = 1`.

The `genrule_example` target in the [root `BUILD` file](BUILD) is an
example for when you don't have a top level binary you can set `stamp =
1` on (even though in this example we still use a `cc_binary` to
demonstrate it working). This is useful for the case you want to embed
this specific information into a static library that you vendor.
