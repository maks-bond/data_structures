load("@rules_cc//cc:defs.bzl", "cc_library","cc_test")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "trie",
    srcs = ["trie.cc"],
    hdrs = ["trie.hh"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "trie_test",
    srcs = ["trie_test.cc"],
    deps = [
        "@gtest//:gtest_main",
        ":trie",
    ]
)

cc_test(
    name = "trie_benchmark",
    srcs = ["trie_benchmark.cc"],
    deps = [
        ":trie",
        "@benchmark//:benchmark_main",
    ]
)

cc_library(
    name = "fenwick_tree",
    hdrs = ["fenwick_tree.hh"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "fenwick_tree_test",
    srcs = ["fenwick_tree_test.cc"],
    deps = [
        "@gtest//:gtest_main",
        ":fenwick_tree",
    ]
)