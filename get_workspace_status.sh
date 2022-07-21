#!/bin/bash

set -euo pipefail

git_rev=$(git rev-parse HEAD)

echo "BUILD_SCM_REVISION ${git_rev}"
