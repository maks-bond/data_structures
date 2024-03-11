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