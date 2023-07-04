load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_library(
	name = "partial",
	srcs = ["partial.cpp"],
	hdrs = ["partial.hpp"],
)
cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [ 
	    "//template:partial",
        "//const:const",
        "//friend_function:friend",
	    "//complex:complex",
        "//conv2d:conv2d",
    ],
)
