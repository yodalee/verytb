#pragma once
// Direct include
#include "verilog/dtype/vint.h"
// C system headers
// C++ standard library headers
#include <utility>
#include <vector>
// Other libraries' .h files.
// Your project's .h files.

struct BinaryPattern {
	std::vector<uint64_t> lhs, rhs, result;
};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 7>
> pattern_addassign7 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000001llu}},
		{{0x0000000000000000llu}, {0x000000000000007fllu}, {0x000000000000007fllu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x000000000000007ellu}, {0x000000000000007fllu}},
		{{0x0000000000000003llu}, {0x000000000000005ellu}, {0x0000000000000061llu}},
		{{0x000000000000000bllu}, {0x000000000000004bllu}, {0x0000000000000056llu}},
		{{0x000000000000001cllu}, {0x0000000000000011llu}, {0x000000000000002dllu}},
		{{0x0000000000000023llu}, {0x000000000000001fllu}, {0x0000000000000042llu}},
		{{0x0000000000000051llu}, {0x000000000000000ellu}, {0x000000000000005fllu}},
		{{0x0000000000000056llu}, {0x000000000000005ellu}, {0x0000000000000034llu}},
		{{0x000000000000005ellu}, {0x000000000000000dllu}, {0x000000000000006bllu}},
		{{0x0000000000000072llu}, {0x0000000000000045llu}, {0x0000000000000037llu}},
		{{0x000000000000007ellu}, {0x0000000000000001llu}, {0x000000000000007fllu}},
		{{0x000000000000007fllu}, {0x0000000000000000llu}, {0x000000000000007fllu}},
		{{0x000000000000007fllu}, {0x000000000000007fllu}, {0x000000000000007ellu}},
}, std::integral_constant<unsigned, 7>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 16>
> pattern_addassign16 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000001llu}},
		{{0x0000000000000000llu}, {0x000000000000ffffllu}, {0x000000000000ffffllu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x000000000000fffellu}, {0x000000000000ffffllu}},
		{{0x0000000000000667llu}, {0x000000000000bdd6llu}, {0x000000000000c43dllu}},
		{{0x0000000000001641llu}, {0x000000000000972allu}, {0x000000000000ad6bllu}},
		{{0x0000000000003924llu}, {0x00000000000023b8llu}, {0x0000000000005cdcllu}},
		{{0x0000000000004668llu}, {0x0000000000003eb1llu}, {0x0000000000008519llu}},
		{{0x000000000000a3b1llu}, {0x0000000000001c80llu}, {0x000000000000c031llu}},
		{{0x000000000000ad3cllu}, {0x000000000000bd9cllu}, {0x0000000000006ad8llu}},
		{{0x000000000000bc89llu}, {0x0000000000001a3dllu}, {0x000000000000d6c6llu}},
		{{0x000000000000e465llu}, {0x0000000000008b9dllu}, {0x0000000000007002llu}},
		{{0x000000000000fffellu}, {0x0000000000000001llu}, {0x000000000000ffffllu}},
		{{0x000000000000ffffllu}, {0x0000000000000000llu}, {0x000000000000ffffllu}},
		{{0x000000000000ffffllu}, {0x000000000000ffffllu}, {0x000000000000fffellu}},
}, std::integral_constant<unsigned, 16>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 63>
> pattern_addassign63 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000001llu}},
		{{0x0000000000000000llu}, {0x7fffffffffffffffllu}, {0x7fffffffffffffffllu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x7ffffffffffffffellu}, {0x7fffffffffffffffllu}},
		{{0x041174796c031199llu}, {0x0bfe34ad07a0ca6ellu}, {0x100fa92673a3dc07llu}},
		{{0x0d1e8fd3bc8960a9llu}, {0x5ece3359ad3c2d6dllu}, {0x6becc32d69c58e16llu}},
		{{0x0e4018bfa3b1799dllu}, {0x5eeb207d06671ad1llu}, {0x6d2b393caa18946ellu}},
		{{0x1dc7d50c37f8a88bllu}, {0x4d0ef322815ef6d1llu}, {0x6ad6c82eb9579f5cllu}},
		{{0x1f589dc846685257llu}, {0x11dc60f4392456dellu}, {0x3134febc7f8ca935llu}},
		{{0x45ce921ae465e150llu}, {0x4b95423416419f82llu}, {0x1163d44efaa780d2llu}},
		{{0x47d6e0d306cb0fb3llu}, {0x5ba687d832e70629llu}, {0x237d68ab39b215dcllu}},
		{{0x59c50446a65ed389llu}, {0x35b2d3528b8148f6llu}, {0x0f77d79931e01c7fllu}},
		{{0x7ffffffffffffffellu}, {0x0000000000000001llu}, {0x7fffffffffffffffllu}},
		{{0x7fffffffffffffffllu}, {0x0000000000000000llu}, {0x7fffffffffffffffllu}},
		{{0x7fffffffffffffffllu}, {0x7fffffffffffffffllu}, {0x7ffffffffffffffellu}},
}, std::integral_constant<unsigned, 63>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 64>
> pattern_addassign64 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000001llu}},
		{{0x0000000000000000llu}, {0xffffffffffffffffllu}, {0xffffffffffffffffllu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0xfffffffffffffffellu}, {0xffffffffffffffffllu}},
		{{0x0822e8f36c031199llu}, {0x17fc695a07a0ca6ellu}, {0x201f524d73a3dc07llu}},
		{{0x1a3d1fa7bc8960a9llu}, {0xbd9c66b3ad3c2d6dllu}, {0xd7d9865b69c58e16llu}},
		{{0x1c80317fa3b1799dllu}, {0xbdd640fb06671ad1llu}, {0xda56727aaa18946ellu}},
		{{0x3b8faa1837f8a88bllu}, {0x9a1de644815ef6d1llu}, {0xd5ad905cb9579f5cllu}},
		{{0x3eb13b9046685257llu}, {0x23b8c1e9392456dellu}, {0x6269fd797f8ca935llu}},
		{{0x8b9d2434e465e150llu}, {0x972a846916419f82llu}, {0x22c7a89dfaa780d2llu}},
		{{0x8fadc1a606cb0fb3llu}, {0xb74d0fb132e70629llu}, {0x46fad15739b215dcllu}},
		{{0xb38a088ca65ed389llu}, {0x6b65a6a48b8148f6llu}, {0x1eefaf3131e01c7fllu}},
		{{0xfffffffffffffffellu}, {0x0000000000000001llu}, {0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu}, {0x0000000000000000llu}, {0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu}, {0xffffffffffffffffllu}, {0xfffffffffffffffellu}},
}, std::integral_constant<unsigned, 64>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 127>
> pattern_addassign127 {{
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0x0822e8f36c031199llu, 0x0bfe34ad07a0ca6ellu}, {0x3b8faa1837f8a88bllu, 0x4d0ef322815ef6d1llu}, {0x43b2930ba3fbba24llu, 0x590d27cf88ffc13fllu}},
		{{0xc37459eef50bea63llu, 0x0d1539f6562b0f79llu}, {0x6142ea7d17be3111llu, 0x2df3094718c26797llu}, {0x24b7446c0cca1b74llu, 0x3b08433d6eed7711llu}},
		{{0x580d7b71d8f56413llu, 0x21dbd1d39a8dca03llu}, {0x0b1f9163ce9ff57fllu, 0x3ace6f33bacfb3d0llu}, {0x632d0cd5a7955992llu, 0x5caa4107555d7dd3llu}},
		{{0x72ff5d2a386ecbe0llu, 0x239bc0c896da1dacllu}, {0xde8a774bcf36d58bllu, 0x6120998501a9e71fllu}, {0x5189d47607a5a16bllu, 0x04bc5a4d988404ccllu}},
		{{0x28df6ec4ce4a2bbdllu, 0x36183a88b2b9437allu}, {0x47229389571aa876llu, 0x1b8f66bd27cd8130llu}, {0x7002024e2564d433llu, 0x51a7a145da86c4aallu}},
		{{0x8fadc1a606cb0fb3llu, 0x5ba687d832e70629llu}, {0xb38a088ca65ed389llu, 0x35b2d3528b8148f6llu}, {0x4337ca32ad29e33cllu, 0x11595b2abe684f20llu}},
		{{0x1a3d1fa7bc8960a9llu, 0x5ece3359ad3c2d6dllu}, {0x8b9d2434e465e150llu, 0x4b95423416419f82llu}, {0xa5da43dca0ef41f9llu, 0x2a63758dc37dccefllu}},
		{{0x1c80317fa3b1799dllu, 0x5eeb207d06671ad1llu}, {0x3eb13b9046685257llu, 0x11dc60f4392456dellu}, {0x5b316d0fea19cbf4llu, 0x70c781713f8b71afllu}},
		{{0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0xfffffffffffffffellu, 0x7fffffffffffffffllu}},
}, std::integral_constant<unsigned, 127>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 128>
> pattern_addassign128 {{
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0x0822e8f36c031199llu, 0x17fc695a07a0ca6ellu}, {0x3b8faa1837f8a88bllu, 0x9a1de644815ef6d1llu}, {0x43b2930ba3fbba24llu, 0xb21a4f9e88ffc13fllu}},
		{{0xc37459eef50bea63llu, 0x1a2a73ed562b0f79llu}, {0x6142ea7d17be3111llu, 0x5be6128e18c26797llu}, {0x24b7446c0cca1b74llu, 0x7610867b6eed7711llu}},
		{{0x580d7b71d8f56413llu, 0x43b7a3a69a8dca03llu}, {0x0b1f9163ce9ff57fllu, 0x759cde66bacfb3d0llu}, {0x632d0cd5a7955992llu, 0xb954820d555d7dd3llu}},
		{{0x72ff5d2a386ecbe0llu, 0x4737819096da1dacllu}, {0xde8a774bcf36d58bllu, 0xc241330b01a9e71fllu}, {0x5189d47607a5a16bllu, 0x0978b49b988404ccllu}},
		{{0x28df6ec4ce4a2bbdllu, 0x6c307511b2b9437allu}, {0x47229389571aa876llu, 0x371ecd7b27cd8130llu}, {0x7002024e2564d433llu, 0xa34f428cda86c4aallu}},
		{{0x8fadc1a606cb0fb3llu, 0xb74d0fb132e70629llu}, {0xb38a088ca65ed389llu, 0x6b65a6a48b8148f6llu}, {0x4337ca32ad29e33cllu, 0x22b2b655be684f20llu}},
		{{0x1a3d1fa7bc8960a9llu, 0xbd9c66b3ad3c2d6dllu}, {0x8b9d2434e465e150llu, 0x972a846916419f82llu}, {0xa5da43dca0ef41f9llu, 0x54c6eb1cc37dccefllu}},
		{{0x1c80317fa3b1799dllu, 0xbdd640fb06671ad1llu}, {0x3eb13b9046685257llu, 0x23b8c1e9392456dellu}, {0x5b316d0fea19cbf4llu, 0xe18f02e43f8b71afllu}},
		{{0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0xfffffffffffffffellu, 0xffffffffffffffffllu}},
}, std::integral_constant<unsigned, 128>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 7>
> pattern_subassign7 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x000000000000007fllu}},
		{{0x0000000000000000llu}, {0x000000000000007fllu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x000000000000007ellu}, {0x0000000000000003llu}},
		{{0x0000000000000003llu}, {0x000000000000005ellu}, {0x0000000000000025llu}},
		{{0x000000000000000bllu}, {0x000000000000004bllu}, {0x0000000000000040llu}},
		{{0x000000000000001cllu}, {0x0000000000000011llu}, {0x000000000000000bllu}},
		{{0x0000000000000023llu}, {0x000000000000001fllu}, {0x0000000000000004llu}},
		{{0x0000000000000051llu}, {0x000000000000000ellu}, {0x0000000000000043llu}},
		{{0x0000000000000056llu}, {0x000000000000005ellu}, {0x0000000000000078llu}},
		{{0x000000000000005ellu}, {0x000000000000000dllu}, {0x0000000000000051llu}},
		{{0x0000000000000072llu}, {0x0000000000000045llu}, {0x000000000000002dllu}},
		{{0x000000000000007ellu}, {0x0000000000000001llu}, {0x000000000000007dllu}},
		{{0x000000000000007fllu}, {0x0000000000000000llu}, {0x000000000000007fllu}},
		{{0x000000000000007fllu}, {0x000000000000007fllu}, {0x0000000000000000llu}},
}, std::integral_constant<unsigned, 7>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 16>
> pattern_subassign16 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x000000000000ffffllu}},
		{{0x0000000000000000llu}, {0x000000000000ffffllu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x000000000000fffellu}, {0x0000000000000003llu}},
		{{0x0000000000000667llu}, {0x000000000000bdd6llu}, {0x0000000000004891llu}},
		{{0x0000000000001641llu}, {0x000000000000972allu}, {0x0000000000007f17llu}},
		{{0x0000000000003924llu}, {0x00000000000023b8llu}, {0x000000000000156cllu}},
		{{0x0000000000004668llu}, {0x0000000000003eb1llu}, {0x00000000000007b7llu}},
		{{0x000000000000a3b1llu}, {0x0000000000001c80llu}, {0x0000000000008731llu}},
		{{0x000000000000ad3cllu}, {0x000000000000bd9cllu}, {0x000000000000efa0llu}},
		{{0x000000000000bc89llu}, {0x0000000000001a3dllu}, {0x000000000000a24cllu}},
		{{0x000000000000e465llu}, {0x0000000000008b9dllu}, {0x00000000000058c8llu}},
		{{0x000000000000fffellu}, {0x0000000000000001llu}, {0x000000000000fffdllu}},
		{{0x000000000000ffffllu}, {0x0000000000000000llu}, {0x000000000000ffffllu}},
		{{0x000000000000ffffllu}, {0x000000000000ffffllu}, {0x0000000000000000llu}},
}, std::integral_constant<unsigned, 16>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 63>
> pattern_subassign63 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x7fffffffffffffffllu}},
		{{0x0000000000000000llu}, {0x7fffffffffffffffllu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x7ffffffffffffffellu}, {0x0000000000000003llu}},
		{{0x041174796c031199llu}, {0x0bfe34ad07a0ca6ellu}, {0x78133fcc6462472bllu}},
		{{0x0d1e8fd3bc8960a9llu}, {0x5ece3359ad3c2d6dllu}, {0x2e505c7a0f4d333cllu}},
		{{0x0e4018bfa3b1799dllu}, {0x5eeb207d06671ad1llu}, {0x2f54f8429d4a5eccllu}},
		{{0x1dc7d50c37f8a88bllu}, {0x4d0ef322815ef6d1llu}, {0x50b8e1e9b699b1ballu}},
		{{0x1f589dc846685257llu}, {0x11dc60f4392456dellu}, {0x0d7c3cd40d43fb79llu}},
		{{0x45ce921ae465e150llu}, {0x4b95423416419f82llu}, {0x7a394fe6ce2441cellu}},
		{{0x47d6e0d306cb0fb3llu}, {0x5ba687d832e70629llu}, {0x6c3058fad3e4098allu}},
		{{0x59c50446a65ed389llu}, {0x35b2d3528b8148f6llu}, {0x241230f41add8a93llu}},
		{{0x7ffffffffffffffellu}, {0x0000000000000001llu}, {0x7ffffffffffffffdllu}},
		{{0x7fffffffffffffffllu}, {0x0000000000000000llu}, {0x7fffffffffffffffllu}},
		{{0x7fffffffffffffffllu}, {0x7fffffffffffffffllu}, {0x0000000000000000llu}},
}, std::integral_constant<unsigned, 63>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 64>
> pattern_subassign64 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0xffffffffffffffffllu}},
		{{0x0000000000000000llu}, {0xffffffffffffffffllu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0xfffffffffffffffellu}, {0x0000000000000003llu}},
		{{0x0822e8f36c031199llu}, {0x17fc695a07a0ca6ellu}, {0xf0267f996462472bllu}},
		{{0x1a3d1fa7bc8960a9llu}, {0xbd9c66b3ad3c2d6dllu}, {0x5ca0b8f40f4d333cllu}},
		{{0x1c80317fa3b1799dllu}, {0xbdd640fb06671ad1llu}, {0x5ea9f0849d4a5eccllu}},
		{{0x3b8faa1837f8a88bllu}, {0x9a1de644815ef6d1llu}, {0xa171c3d3b699b1ballu}},
		{{0x3eb13b9046685257llu}, {0x23b8c1e9392456dellu}, {0x1af879a70d43fb79llu}},
		{{0x8b9d2434e465e150llu}, {0x972a846916419f82llu}, {0xf4729fcbce2441cellu}},
		{{0x8fadc1a606cb0fb3llu}, {0xb74d0fb132e70629llu}, {0xd860b1f4d3e4098allu}},
		{{0xb38a088ca65ed389llu}, {0x6b65a6a48b8148f6llu}, {0x482461e81add8a93llu}},
		{{0xfffffffffffffffellu}, {0x0000000000000001llu}, {0xfffffffffffffffdllu}},
		{{0xffffffffffffffffllu}, {0x0000000000000000llu}, {0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu}, {0xffffffffffffffffllu}, {0x0000000000000000llu}},
}, std::integral_constant<unsigned, 64>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 127>
> pattern_subassign127 {{
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0x0000000000000003llu, 0x0000000000000000llu}},
		{{0x0822e8f36c031199llu, 0x0bfe34ad07a0ca6ellu}, {0x3b8faa1837f8a88bllu, 0x4d0ef322815ef6d1llu}, {0xcc933edb340a690ellu, 0x3eef418a8641d39cllu}},
		{{0xc37459eef50bea63llu, 0x0d1539f6562b0f79llu}, {0x6142ea7d17be3111llu, 0x2df3094718c26797llu}, {0x62316f71dd4db952llu, 0x5f2230af3d68a7e2llu}},
		{{0x580d7b71d8f56413llu, 0x21dbd1d39a8dca03llu}, {0x0b1f9163ce9ff57fllu, 0x3ace6f33bacfb3d0llu}, {0x4cedea0e0a556e94llu, 0x670d629fdfbe1633llu}},
		{{0x72ff5d2a386ecbe0llu, 0x239bc0c896da1dacllu}, {0xde8a774bcf36d58bllu, 0x6120998501a9e71fllu}, {0x9474e5de6937f655llu, 0x427b27439530368cllu}},
		{{0x28df6ec4ce4a2bbdllu, 0x36183a88b2b9437allu}, {0x47229389571aa876llu, 0x1b8f66bd27cd8130llu}, {0xe1bcdb3b772f8347llu, 0x1a88d3cb8aebc249llu}},
		{{0x8fadc1a606cb0fb3llu, 0x5ba687d832e70629llu}, {0xb38a088ca65ed389llu, 0x35b2d3528b8148f6llu}, {0xdc23b919606c3c2allu, 0x25f3b485a765bd32llu}},
		{{0x1a3d1fa7bc8960a9llu, 0x5ece3359ad3c2d6dllu}, {0x8b9d2434e465e150llu, 0x4b95423416419f82llu}, {0x8e9ffb72d8237f59llu, 0x1338f12596fa8deallu}},
		{{0x1c80317fa3b1799dllu, 0x5eeb207d06671ad1llu}, {0x3eb13b9046685257llu, 0x11dc60f4392456dellu}, {0xddcef5ef5d492746llu, 0x4d0ebf88cd42c3f2llu}},
		{{0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffdllu, 0x7fffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}},
}, std::integral_constant<unsigned, 127>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 128>
> pattern_subassign128 {{
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0x0000000000000003llu, 0x0000000000000000llu}},
		{{0x0822e8f36c031199llu, 0x17fc695a07a0ca6ellu}, {0x3b8faa1837f8a88bllu, 0x9a1de644815ef6d1llu}, {0xcc933edb340a690ellu, 0x7dde83158641d39cllu}},
		{{0xc37459eef50bea63llu, 0x1a2a73ed562b0f79llu}, {0x6142ea7d17be3111llu, 0x5be6128e18c26797llu}, {0x62316f71dd4db952llu, 0xbe44615f3d68a7e2llu}},
		{{0x580d7b71d8f56413llu, 0x43b7a3a69a8dca03llu}, {0x0b1f9163ce9ff57fllu, 0x759cde66bacfb3d0llu}, {0x4cedea0e0a556e94llu, 0xce1ac53fdfbe1633llu}},
		{{0x72ff5d2a386ecbe0llu, 0x4737819096da1dacllu}, {0xde8a774bcf36d58bllu, 0xc241330b01a9e71fllu}, {0x9474e5de6937f655llu, 0x84f64e859530368cllu}},
		{{0x28df6ec4ce4a2bbdllu, 0x6c307511b2b9437allu}, {0x47229389571aa876llu, 0x371ecd7b27cd8130llu}, {0xe1bcdb3b772f8347llu, 0x3511a7968aebc249llu}},
		{{0x8fadc1a606cb0fb3llu, 0xb74d0fb132e70629llu}, {0xb38a088ca65ed389llu, 0x6b65a6a48b8148f6llu}, {0xdc23b919606c3c2allu, 0x4be7690ca765bd32llu}},
		{{0x1a3d1fa7bc8960a9llu, 0xbd9c66b3ad3c2d6dllu}, {0x8b9d2434e465e150llu, 0x972a846916419f82llu}, {0x8e9ffb72d8237f59llu, 0x2671e24a96fa8deallu}},
		{{0x1c80317fa3b1799dllu, 0xbdd640fb06671ad1llu}, {0x3eb13b9046685257llu, 0x23b8c1e9392456dellu}, {0xddcef5ef5d492746llu, 0x9a1d7f11cd42c3f2llu}},
		{{0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffdllu, 0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}},
}, std::integral_constant<unsigned, 128>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 7>
> pattern_mulassign7 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x000000000000007fllu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x000000000000007ellu}, {0x000000000000007ellu}},
		{{0x0000000000000003llu}, {0x000000000000005ellu}, {0x000000000000001allu}},
		{{0x000000000000000bllu}, {0x000000000000004bllu}, {0x0000000000000039llu}},
		{{0x000000000000001cllu}, {0x0000000000000011llu}, {0x000000000000005cllu}},
		{{0x0000000000000023llu}, {0x000000000000001fllu}, {0x000000000000003dllu}},
		{{0x0000000000000051llu}, {0x000000000000000ellu}, {0x000000000000006ellu}},
		{{0x0000000000000056llu}, {0x000000000000005ellu}, {0x0000000000000014llu}},
		{{0x000000000000005ellu}, {0x000000000000000dllu}, {0x0000000000000046llu}},
		{{0x0000000000000072llu}, {0x0000000000000045llu}, {0x000000000000003allu}},
		{{0x000000000000007ellu}, {0x0000000000000001llu}, {0x000000000000007ellu}},
		{{0x000000000000007fllu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x000000000000007fllu}, {0x000000000000007fllu}, {0x0000000000000001llu}},
}, std::integral_constant<unsigned, 7>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 16>
> pattern_mulassign16 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x000000000000ffffllu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x000000000000fffellu}, {0x000000000000fffellu}},
		{{0x0000000000000667llu}, {0x000000000000bdd6llu}, {0x000000000000651allu}},
		{{0x0000000000001641llu}, {0x000000000000972allu}, {0x000000000000fdaallu}},
		{{0x0000000000003924llu}, {0x00000000000023b8llu}, {0x000000000000fde0llu}},
		{{0x0000000000004668llu}, {0x0000000000003eb1llu}, {0x000000000000dde8llu}},
		{{0x000000000000a3b1llu}, {0x0000000000001c80llu}, {0x0000000000003480llu}},
		{{0x000000000000ad3cllu}, {0x000000000000bd9cllu}, {0x000000000000dc90llu}},
		{{0x000000000000bc89llu}, {0x0000000000001a3dllu}, {0x000000000000d6a5llu}},
		{{0x000000000000e465llu}, {0x0000000000008b9dllu}, {0x000000000000e8f1llu}},
		{{0x000000000000fffellu}, {0x0000000000000001llu}, {0x000000000000fffellu}},
		{{0x000000000000ffffllu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x000000000000ffffllu}, {0x000000000000ffffllu}, {0x0000000000000001llu}},
}, std::integral_constant<unsigned, 16>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 63>
> pattern_mulassign63 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x7fffffffffffffffllu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x7ffffffffffffffellu}, {0x7ffffffffffffffellu}},
		{{0x041174796c031199llu}, {0x0bfe34ad07a0ca6ellu}, {0x49b36b3203d449bellu}},
		{{0x0d1e8fd3bc8960a9llu}, {0x5ece3359ad3c2d6dllu}, {0x0156c1914917dcf5llu}},
		{{0x0e4018bfa3b1799dllu}, {0x5eeb207d06671ad1llu}, {0x7dc3b1ff46693b2dllu}},
		{{0x1dc7d50c37f8a88bllu}, {0x4d0ef322815ef6d1llu}, {0x372bda7492012b7bllu}},
		{{0x1f589dc846685257llu}, {0x11dc60f4392456dellu}, {0x7fc457410d5ca172llu}},
		{{0x45ce921ae465e150llu}, {0x4b95423416419f82llu}, {0x647208fe57fd1aa0llu}},
		{{0x47d6e0d306cb0fb3llu}, {0x5ba687d832e70629llu}, {0x401c6248f968b5abllu}},
		{{0x59c50446a65ed389llu}, {0x35b2d3528b8148f6llu}, {0x1570fa3485a6cda6llu}},
		{{0x7ffffffffffffffellu}, {0x0000000000000001llu}, {0x7ffffffffffffffellu}},
		{{0x7fffffffffffffffllu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x7fffffffffffffffllu}, {0x7fffffffffffffffllu}, {0x0000000000000001llu}},
}, std::integral_constant<unsigned, 63>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 64>
> pattern_mulassign64 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0xffffffffffffffffllu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0xfffffffffffffffellu}, {0xfffffffffffffffellu}},
		{{0x0822e8f36c031199llu}, {0x17fc695a07a0ca6ellu}, {0x97cfb40303d449bellu}},
		{{0x1a3d1fa7bc8960a9llu}, {0xbd9c66b3ad3c2d6dllu}, {0xecdde93f4917dcf5llu}},
		{{0x1c80317fa3b1799dllu}, {0xbdd640fb06671ad1llu}, {0xa187e20546693b2dllu}},
		{{0x3b8faa1837f8a88bllu}, {0x9a1de644815ef6d1llu}, {0x520ea4b692012b7bllu}},
		{{0x3eb13b9046685257llu}, {0x23b8c1e9392456dellu}, {0x3639c7f40d5ca172llu}},
		{{0x8b9d2434e465e150llu}, {0x972a846916419f82llu}, {0x996ea5c257fd1aa0llu}},
		{{0x8fadc1a606cb0fb3llu}, {0xb74d0fb132e70629llu}, {0x85aa09cef968b5abllu}},
		{{0xb38a088ca65ed389llu}, {0x6b65a6a48b8148f6llu}, {0xd038725a85a6cda6llu}},
		{{0xfffffffffffffffellu}, {0x0000000000000001llu}, {0xfffffffffffffffellu}},
		{{0xffffffffffffffffllu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0xffffffffffffffffllu}, {0xffffffffffffffffllu}, {0x0000000000000001llu}},
}, std::integral_constant<unsigned, 64>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 127>
> pattern_mulassign127 {{
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0xfffffffffffffffellu, 0x7fffffffffffffffllu}},
		{{0x0822e8f36c031199llu, 0x0bfe34ad07a0ca6ellu}, {0x3b8faa1837f8a88bllu, 0x4d0ef322815ef6d1llu}, {0x8d49c726946ef613llu, 0x175597f543eb6c2dllu}},
		{{0xc37459eef50bea63llu, 0x0d1539f6562b0f79llu}, {0x6142ea7d17be3111llu, 0x2df3094718c26797llu}, {0xf2e4970368218393llu, 0x1115a5632494f5dfllu}},
		{{0x580d7b71d8f56413llu, 0x21dbd1d39a8dca03llu}, {0x0b1f9163ce9ff57fllu, 0x3ace6f33bacfb3d0llu}, {0xb200df66ec4fd46dllu, 0x699fc0bba4909700llu}},
		{{0x72ff5d2a386ecbe0llu, 0x239bc0c896da1dacllu}, {0xde8a774bcf36d58bllu, 0x6120998501a9e71fllu}, {0xe3b00fb9f50a12a0llu, 0x5421ea34978e92c3llu}},
		{{0x28df6ec4ce4a2bbdllu, 0x36183a88b2b9437allu}, {0x47229389571aa876llu, 0x1b8f66bd27cd8130llu}, {0xd0af4da26f16311ellu, 0x42267bbaaacc0ca9llu}},
		{{0x8fadc1a606cb0fb3llu, 0x5ba687d832e70629llu}, {0xb38a088ca65ed389llu, 0x35b2d3528b8148f6llu}, {0x8cfed214d655efcbllu, 0x7f1b06671735257dllu}},
		{{0x1a3d1fa7bc8960a9llu, 0x5ece3359ad3c2d6dllu}, {0x8b9d2434e465e150llu, 0x4b95423416419f82llu}, {0x752873bd4f8fbdd0llu, 0x75afcacca9f5299allu}},
		{{0x1c80317fa3b1799dllu, 0x5eeb207d06671ad1llu}, {0x3eb13b9046685257llu, 0x11dc60f4392456dellu}, {0xd8715379d00c9e5bllu, 0x2d6409ed9e9f59a3llu}},
		{{0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0x7fffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}},
}, std::integral_constant<unsigned, 127>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 128>
> pattern_mulassign128 {{
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0xfffffffffffffffellu, 0xffffffffffffffffllu}},
		{{0x0822e8f36c031199llu, 0x17fc695a07a0ca6ellu}, {0x3b8faa1837f8a88bllu, 0x9a1de644815ef6d1llu}, {0x8d49c726946ef613llu, 0xdd004b3643eb6c2dllu}},
		{{0xc37459eef50bea63llu, 0x1a2a73ed562b0f79llu}, {0x6142ea7d17be3111llu, 0x5be6128e18c26797llu}, {0xf2e4970368218393llu, 0xfa6d423f2494f5dfllu}},
		{{0x580d7b71d8f56413llu, 0x43b7a3a69a8dca03llu}, {0x0b1f9163ce9ff57fllu, 0x759cde66bacfb3d0llu}, {0xb200df66ec4fd46dllu, 0x2619f431a4909700llu}},
		{{0x72ff5d2a386ecbe0llu, 0x4737819096da1dacllu}, {0xde8a774bcf36d58bllu, 0xc241330b01a9e71fllu}, {0xe3b00fb9f50a12a0llu, 0x4121960c978e92c3llu}},
		{{0x28df6ec4ce4a2bbdllu, 0x6c307511b2b9437allu}, {0x47229389571aa876llu, 0x371ecd7b27cd8130llu}, {0xd0af4da26f16311ellu, 0x9eb22326aacc0ca9llu}},
		{{0x8fadc1a606cb0fb3llu, 0xb74d0fb132e70629llu}, {0xb38a088ca65ed389llu, 0x6b65a6a48b8148f6llu}, {0x8cfed214d655efcbllu, 0x695124de1735257dllu}},
		{{0x1a3d1fa7bc8960a9llu, 0xbd9c66b3ad3c2d6dllu}, {0x8b9d2434e465e150llu, 0x972a846916419f82llu}, {0x752873bd4f8fbdd0llu, 0x747d85e9a9f5299allu}},
		{{0x1c80317fa3b1799dllu, 0xbdd640fb06671ad1llu}, {0x3eb13b9046685257llu, 0x23b8c1e9392456dellu}, {0xd8715379d00c9e5bllu, 0x8d44b4009e9f59a3llu}},
		{{0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}},
}, std::integral_constant<unsigned, 128>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 7>
> pattern_andassign7 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x000000000000007fllu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x000000000000007ellu}, {0x0000000000000000llu}},
		{{0x0000000000000003llu}, {0x000000000000005ellu}, {0x0000000000000002llu}},
		{{0x000000000000000bllu}, {0x000000000000004bllu}, {0x000000000000000bllu}},
		{{0x000000000000001cllu}, {0x0000000000000011llu}, {0x0000000000000010llu}},
		{{0x0000000000000023llu}, {0x000000000000001fllu}, {0x0000000000000003llu}},
		{{0x0000000000000051llu}, {0x000000000000000ellu}, {0x0000000000000000llu}},
		{{0x0000000000000056llu}, {0x000000000000005ellu}, {0x0000000000000056llu}},
		{{0x000000000000005ellu}, {0x000000000000000dllu}, {0x000000000000000cllu}},
		{{0x0000000000000072llu}, {0x0000000000000045llu}, {0x0000000000000040llu}},
		{{0x000000000000007ellu}, {0x0000000000000001llu}, {0x0000000000000000llu}},
		{{0x000000000000007fllu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x000000000000007fllu}, {0x000000000000007fllu}, {0x000000000000007fllu}},
}, std::integral_constant<unsigned, 7>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 16>
> pattern_andassign16 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x000000000000ffffllu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x000000000000fffellu}, {0x0000000000000000llu}},
		{{0x0000000000000667llu}, {0x000000000000bdd6llu}, {0x0000000000000446llu}},
		{{0x0000000000001641llu}, {0x000000000000972allu}, {0x0000000000001600llu}},
		{{0x0000000000003924llu}, {0x00000000000023b8llu}, {0x0000000000002120llu}},
		{{0x0000000000004668llu}, {0x0000000000003eb1llu}, {0x0000000000000620llu}},
		{{0x000000000000a3b1llu}, {0x0000000000001c80llu}, {0x0000000000000080llu}},
		{{0x000000000000ad3cllu}, {0x000000000000bd9cllu}, {0x000000000000ad1cllu}},
		{{0x000000000000bc89llu}, {0x0000000000001a3dllu}, {0x0000000000001809llu}},
		{{0x000000000000e465llu}, {0x0000000000008b9dllu}, {0x0000000000008005llu}},
		{{0x000000000000fffellu}, {0x0000000000000001llu}, {0x0000000000000000llu}},
		{{0x000000000000ffffllu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x000000000000ffffllu}, {0x000000000000ffffllu}, {0x000000000000ffffllu}},
}, std::integral_constant<unsigned, 16>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 63>
> pattern_andassign63 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x7fffffffffffffffllu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x7ffffffffffffffellu}, {0x0000000000000000llu}},
		{{0x041174796c031199llu}, {0x0bfe34ad07a0ca6ellu}, {0x0010342904000008llu}},
		{{0x0d1e8fd3bc8960a9llu}, {0x5ece3359ad3c2d6dllu}, {0x0c0e0351ac082029llu}},
		{{0x0e4018bfa3b1799dllu}, {0x5eeb207d06671ad1llu}, {0x0e40003d02211891llu}},
		{{0x1dc7d50c37f8a88bllu}, {0x4d0ef322815ef6d1llu}, {0x0d06d1000158a081llu}},
		{{0x1f589dc846685257llu}, {0x11dc60f4392456dellu}, {0x115800c000205256llu}},
		{{0x45ce921ae465e150llu}, {0x4b95423416419f82llu}, {0x4184021004418100llu}},
		{{0x47d6e0d306cb0fb3llu}, {0x5ba687d832e70629llu}, {0x438680d002c30621llu}},
		{{0x59c50446a65ed389llu}, {0x35b2d3528b8148f6llu}, {0x1180004282004080llu}},
		{{0x7ffffffffffffffellu}, {0x0000000000000001llu}, {0x0000000000000000llu}},
		{{0x7fffffffffffffffllu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x7fffffffffffffffllu}, {0x7fffffffffffffffllu}, {0x7fffffffffffffffllu}},
}, std::integral_constant<unsigned, 63>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 64>
> pattern_andassign64 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0xffffffffffffffffllu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000001llu}, {0xfffffffffffffffellu}, {0x0000000000000000llu}},
		{{0x0822e8f36c031199llu}, {0x17fc695a07a0ca6ellu}, {0x0020685204000008llu}},
		{{0x1a3d1fa7bc8960a9llu}, {0xbd9c66b3ad3c2d6dllu}, {0x181c06a3ac082029llu}},
		{{0x1c80317fa3b1799dllu}, {0xbdd640fb06671ad1llu}, {0x1c80007b02211891llu}},
		{{0x3b8faa1837f8a88bllu}, {0x9a1de644815ef6d1llu}, {0x1a0da2000158a081llu}},
		{{0x3eb13b9046685257llu}, {0x23b8c1e9392456dellu}, {0x22b0018000205256llu}},
		{{0x8b9d2434e465e150llu}, {0x972a846916419f82llu}, {0x8308042004418100llu}},
		{{0x8fadc1a606cb0fb3llu}, {0xb74d0fb132e70629llu}, {0x870d01a002c30621llu}},
		{{0xb38a088ca65ed389llu}, {0x6b65a6a48b8148f6llu}, {0x2300008482004080llu}},
		{{0xfffffffffffffffellu}, {0x0000000000000001llu}, {0x0000000000000000llu}},
		{{0xffffffffffffffffllu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0xffffffffffffffffllu}, {0xffffffffffffffffllu}, {0xffffffffffffffffllu}},
}, std::integral_constant<unsigned, 64>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 127>
> pattern_andassign127 {{
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0822e8f36c031199llu, 0x0bfe34ad07a0ca6ellu}, {0x3b8faa1837f8a88bllu, 0x4d0ef322815ef6d1llu}, {0x0802a81024000089llu, 0x090e30200100c240llu}},
		{{0xc37459eef50bea63llu, 0x0d1539f6562b0f79llu}, {0x6142ea7d17be3111llu, 0x2df3094718c26797llu}, {0x4140486c150a2001llu, 0x0d11094610020711llu}},
		{{0x580d7b71d8f56413llu, 0x21dbd1d39a8dca03llu}, {0x0b1f9163ce9ff57fllu, 0x3ace6f33bacfb3d0llu}, {0x080d1161c8956413llu, 0x20ca41139a8d8200llu}},
		{{0x72ff5d2a386ecbe0llu, 0x239bc0c896da1dacllu}, {0xde8a774bcf36d58bllu, 0x6120998501a9e71fllu}, {0x528a550a0826c180llu, 0x210080800088050cllu}},
		{{0x28df6ec4ce4a2bbdllu, 0x36183a88b2b9437allu}, {0x47229389571aa876llu, 0x1b8f66bd27cd8130llu}, {0x00020280460a2834llu, 0x1208228822890130llu}},
		{{0x8fadc1a606cb0fb3llu, 0x5ba687d832e70629llu}, {0xb38a088ca65ed389llu, 0x35b2d3528b8148f6llu}, {0x83880084064a0381llu, 0x11a2835002810020llu}},
		{{0x1a3d1fa7bc8960a9llu, 0x5ece3359ad3c2d6dllu}, {0x8b9d2434e465e150llu, 0x4b95423416419f82llu}, {0x0a1d0424a4016000llu, 0x4a84021004000d00llu}},
		{{0x1c80317fa3b1799dllu, 0x5eeb207d06671ad1llu}, {0x3eb13b9046685257llu, 0x11dc60f4392456dellu}, {0x1c80311002205015llu, 0x10c82074002412d0llu}},
		{{0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
}, std::integral_constant<unsigned, 127>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 128>
> pattern_andassign128 {{
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0822e8f36c031199llu, 0x17fc695a07a0ca6ellu}, {0x3b8faa1837f8a88bllu, 0x9a1de644815ef6d1llu}, {0x0802a81024000089llu, 0x121c60400100c240llu}},
		{{0xc37459eef50bea63llu, 0x1a2a73ed562b0f79llu}, {0x6142ea7d17be3111llu, 0x5be6128e18c26797llu}, {0x4140486c150a2001llu, 0x1a22128c10020711llu}},
		{{0x580d7b71d8f56413llu, 0x43b7a3a69a8dca03llu}, {0x0b1f9163ce9ff57fllu, 0x759cde66bacfb3d0llu}, {0x080d1161c8956413llu, 0x419482269a8d8200llu}},
		{{0x72ff5d2a386ecbe0llu, 0x4737819096da1dacllu}, {0xde8a774bcf36d58bllu, 0xc241330b01a9e71fllu}, {0x528a550a0826c180llu, 0x420101000088050cllu}},
		{{0x28df6ec4ce4a2bbdllu, 0x6c307511b2b9437allu}, {0x47229389571aa876llu, 0x371ecd7b27cd8130llu}, {0x00020280460a2834llu, 0x2410451122890130llu}},
		{{0x8fadc1a606cb0fb3llu, 0xb74d0fb132e70629llu}, {0xb38a088ca65ed389llu, 0x6b65a6a48b8148f6llu}, {0x83880084064a0381llu, 0x234506a002810020llu}},
		{{0x1a3d1fa7bc8960a9llu, 0xbd9c66b3ad3c2d6dllu}, {0x8b9d2434e465e150llu, 0x972a846916419f82llu}, {0x0a1d0424a4016000llu, 0x9508042104000d00llu}},
		{{0x1c80317fa3b1799dllu, 0xbdd640fb06671ad1llu}, {0x3eb13b9046685257llu, 0x23b8c1e9392456dellu}, {0x1c80311002205015llu, 0x219040e9002412d0llu}},
		{{0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
}, std::integral_constant<unsigned, 128>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 7>
> pattern_orassign7 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000001llu}},
		{{0x0000000000000000llu}, {0x000000000000007fllu}, {0x000000000000007fllu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x000000000000007ellu}, {0x000000000000007fllu}},
		{{0x0000000000000003llu}, {0x000000000000005ellu}, {0x000000000000005fllu}},
		{{0x000000000000000bllu}, {0x000000000000004bllu}, {0x000000000000004bllu}},
		{{0x000000000000001cllu}, {0x0000000000000011llu}, {0x000000000000001dllu}},
		{{0x0000000000000023llu}, {0x000000000000001fllu}, {0x000000000000003fllu}},
		{{0x0000000000000051llu}, {0x000000000000000ellu}, {0x000000000000005fllu}},
		{{0x0000000000000056llu}, {0x000000000000005ellu}, {0x000000000000005ellu}},
		{{0x000000000000005ellu}, {0x000000000000000dllu}, {0x000000000000005fllu}},
		{{0x0000000000000072llu}, {0x0000000000000045llu}, {0x0000000000000077llu}},
		{{0x000000000000007ellu}, {0x0000000000000001llu}, {0x000000000000007fllu}},
		{{0x000000000000007fllu}, {0x0000000000000000llu}, {0x000000000000007fllu}},
		{{0x000000000000007fllu}, {0x000000000000007fllu}, {0x000000000000007fllu}},
}, std::integral_constant<unsigned, 7>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 16>
> pattern_orassign16 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000001llu}},
		{{0x0000000000000000llu}, {0x000000000000ffffllu}, {0x000000000000ffffllu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x000000000000fffellu}, {0x000000000000ffffllu}},
		{{0x0000000000000667llu}, {0x000000000000bdd6llu}, {0x000000000000bff7llu}},
		{{0x0000000000001641llu}, {0x000000000000972allu}, {0x000000000000976bllu}},
		{{0x0000000000003924llu}, {0x00000000000023b8llu}, {0x0000000000003bbcllu}},
		{{0x0000000000004668llu}, {0x0000000000003eb1llu}, {0x0000000000007ef9llu}},
		{{0x000000000000a3b1llu}, {0x0000000000001c80llu}, {0x000000000000bfb1llu}},
		{{0x000000000000ad3cllu}, {0x000000000000bd9cllu}, {0x000000000000bdbcllu}},
		{{0x000000000000bc89llu}, {0x0000000000001a3dllu}, {0x000000000000bebdllu}},
		{{0x000000000000e465llu}, {0x0000000000008b9dllu}, {0x000000000000effdllu}},
		{{0x000000000000fffellu}, {0x0000000000000001llu}, {0x000000000000ffffllu}},
		{{0x000000000000ffffllu}, {0x0000000000000000llu}, {0x000000000000ffffllu}},
		{{0x000000000000ffffllu}, {0x000000000000ffffllu}, {0x000000000000ffffllu}},
}, std::integral_constant<unsigned, 16>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 63>
> pattern_orassign63 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000001llu}},
		{{0x0000000000000000llu}, {0x7fffffffffffffffllu}, {0x7fffffffffffffffllu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x7ffffffffffffffellu}, {0x7fffffffffffffffllu}},
		{{0x041174796c031199llu}, {0x0bfe34ad07a0ca6ellu}, {0x0fff74fd6fa3dbffllu}},
		{{0x0d1e8fd3bc8960a9llu}, {0x5ece3359ad3c2d6dllu}, {0x5fdebfdbbdbd6dedllu}},
		{{0x0e4018bfa3b1799dllu}, {0x5eeb207d06671ad1llu}, {0x5eeb38ffa7f77bddllu}},
		{{0x1dc7d50c37f8a88bllu}, {0x4d0ef322815ef6d1llu}, {0x5dcff72eb7fefedbllu}},
		{{0x1f589dc846685257llu}, {0x11dc60f4392456dellu}, {0x1fdcfdfc7f6c56dfllu}},
		{{0x45ce921ae465e150llu}, {0x4b95423416419f82llu}, {0x4fdfd23ef665ffd2llu}},
		{{0x47d6e0d306cb0fb3llu}, {0x5ba687d832e70629llu}, {0x5ff6e7db36ef0fbbllu}},
		{{0x59c50446a65ed389llu}, {0x35b2d3528b8148f6llu}, {0x7df7d756afdfdbffllu}},
		{{0x7ffffffffffffffellu}, {0x0000000000000001llu}, {0x7fffffffffffffffllu}},
		{{0x7fffffffffffffffllu}, {0x0000000000000000llu}, {0x7fffffffffffffffllu}},
		{{0x7fffffffffffffffllu}, {0x7fffffffffffffffllu}, {0x7fffffffffffffffllu}},
}, std::integral_constant<unsigned, 63>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 64>
> pattern_orassign64 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000001llu}},
		{{0x0000000000000000llu}, {0xffffffffffffffffllu}, {0xffffffffffffffffllu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0xfffffffffffffffellu}, {0xffffffffffffffffllu}},
		{{0x0822e8f36c031199llu}, {0x17fc695a07a0ca6ellu}, {0x1ffee9fb6fa3dbffllu}},
		{{0x1a3d1fa7bc8960a9llu}, {0xbd9c66b3ad3c2d6dllu}, {0xbfbd7fb7bdbd6dedllu}},
		{{0x1c80317fa3b1799dllu}, {0xbdd640fb06671ad1llu}, {0xbdd671ffa7f77bddllu}},
		{{0x3b8faa1837f8a88bllu}, {0x9a1de644815ef6d1llu}, {0xbb9fee5cb7fefedbllu}},
		{{0x3eb13b9046685257llu}, {0x23b8c1e9392456dellu}, {0x3fb9fbf97f6c56dfllu}},
		{{0x8b9d2434e465e150llu}, {0x972a846916419f82llu}, {0x9fbfa47df665ffd2llu}},
		{{0x8fadc1a606cb0fb3llu}, {0xb74d0fb132e70629llu}, {0xbfedcfb736ef0fbbllu}},
		{{0xb38a088ca65ed389llu}, {0x6b65a6a48b8148f6llu}, {0xfbefaeacafdfdbffllu}},
		{{0xfffffffffffffffellu}, {0x0000000000000001llu}, {0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu}, {0x0000000000000000llu}, {0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu}, {0xffffffffffffffffllu}, {0xffffffffffffffffllu}},
}, std::integral_constant<unsigned, 64>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 127>
> pattern_orassign127 {{
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0x0822e8f36c031199llu, 0x0bfe34ad07a0ca6ellu}, {0x3b8faa1837f8a88bllu, 0x4d0ef322815ef6d1llu}, {0x3bafeafb7ffbb99bllu, 0x4ffef7af87fefeffllu}},
		{{0xc37459eef50bea63llu, 0x0d1539f6562b0f79llu}, {0x6142ea7d17be3111llu, 0x2df3094718c26797llu}, {0xe376fbfff7bffb73llu, 0x2df739f75eeb6fffllu}},
		{{0x580d7b71d8f56413llu, 0x21dbd1d39a8dca03llu}, {0x0b1f9163ce9ff57fllu, 0x3ace6f33bacfb3d0llu}, {0x5b1ffb73defff57fllu, 0x3bdffff3bacffbd3llu}},
		{{0x72ff5d2a386ecbe0llu, 0x239bc0c896da1dacllu}, {0xde8a774bcf36d58bllu, 0x6120998501a9e71fllu}, {0xfeff7f6bff7edfebllu, 0x63bbd9cd97fbffbfllu}},
		{{0x28df6ec4ce4a2bbdllu, 0x36183a88b2b9437allu}, {0x47229389571aa876llu, 0x1b8f66bd27cd8130llu}, {0x6fffffcddf5aabffllu, 0x3f9f7ebdb7fdc37allu}},
		{{0x8fadc1a606cb0fb3llu, 0x5ba687d832e70629llu}, {0xb38a088ca65ed389llu, 0x35b2d3528b8148f6llu}, {0xbfafc9aea6dfdfbbllu, 0x7fb6d7dabbe74effllu}},
		{{0x1a3d1fa7bc8960a9llu, 0x5ece3359ad3c2d6dllu}, {0x8b9d2434e465e150llu, 0x4b95423416419f82llu}, {0x9bbd3fb7fcede1f9llu, 0x5fdf737dbf7dbfefllu}},
		{{0x1c80317fa3b1799dllu, 0x5eeb207d06671ad1llu}, {0x3eb13b9046685257llu, 0x11dc60f4392456dellu}, {0x3eb13bffe7f97bdfllu, 0x5fff60fd3f675edfllu}},
		{{0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
}, std::integral_constant<unsigned, 127>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 128>
> pattern_orassign128 {{
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0x0822e8f36c031199llu, 0x17fc695a07a0ca6ellu}, {0x3b8faa1837f8a88bllu, 0x9a1de644815ef6d1llu}, {0x3bafeafb7ffbb99bllu, 0x9ffdef5e87fefeffllu}},
		{{0xc37459eef50bea63llu, 0x1a2a73ed562b0f79llu}, {0x6142ea7d17be3111llu, 0x5be6128e18c26797llu}, {0xe376fbfff7bffb73llu, 0x5bee73ef5eeb6fffllu}},
		{{0x580d7b71d8f56413llu, 0x43b7a3a69a8dca03llu}, {0x0b1f9163ce9ff57fllu, 0x759cde66bacfb3d0llu}, {0x5b1ffb73defff57fllu, 0x77bfffe6bacffbd3llu}},
		{{0x72ff5d2a386ecbe0llu, 0x4737819096da1dacllu}, {0xde8a774bcf36d58bllu, 0xc241330b01a9e71fllu}, {0xfeff7f6bff7edfebllu, 0xc777b39b97fbffbfllu}},
		{{0x28df6ec4ce4a2bbdllu, 0x6c307511b2b9437allu}, {0x47229389571aa876llu, 0x371ecd7b27cd8130llu}, {0x6fffffcddf5aabffllu, 0x7f3efd7bb7fdc37allu}},
		{{0x8fadc1a606cb0fb3llu, 0xb74d0fb132e70629llu}, {0xb38a088ca65ed389llu, 0x6b65a6a48b8148f6llu}, {0xbfafc9aea6dfdfbbllu, 0xff6dafb5bbe74effllu}},
		{{0x1a3d1fa7bc8960a9llu, 0xbd9c66b3ad3c2d6dllu}, {0x8b9d2434e465e150llu, 0x972a846916419f82llu}, {0x9bbd3fb7fcede1f9llu, 0xbfbee6fbbf7dbfefllu}},
		{{0x1c80317fa3b1799dllu, 0xbdd640fb06671ad1llu}, {0x3eb13b9046685257llu, 0x23b8c1e9392456dellu}, {0x3eb13bffe7f97bdfllu, 0xbffec1fb3f675edfllu}},
		{{0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
}, std::integral_constant<unsigned, 128>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 7>
> pattern_xorassign7 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000001llu}},
		{{0x0000000000000000llu}, {0x000000000000007fllu}, {0x000000000000007fllu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x000000000000007ellu}, {0x000000000000007fllu}},
		{{0x0000000000000003llu}, {0x000000000000005ellu}, {0x000000000000005dllu}},
		{{0x000000000000000bllu}, {0x000000000000004bllu}, {0x0000000000000040llu}},
		{{0x000000000000001cllu}, {0x0000000000000011llu}, {0x000000000000000dllu}},
		{{0x0000000000000023llu}, {0x000000000000001fllu}, {0x000000000000003cllu}},
		{{0x0000000000000051llu}, {0x000000000000000ellu}, {0x000000000000005fllu}},
		{{0x0000000000000056llu}, {0x000000000000005ellu}, {0x0000000000000008llu}},
		{{0x000000000000005ellu}, {0x000000000000000dllu}, {0x0000000000000053llu}},
		{{0x0000000000000072llu}, {0x0000000000000045llu}, {0x0000000000000037llu}},
		{{0x000000000000007ellu}, {0x0000000000000001llu}, {0x000000000000007fllu}},
		{{0x000000000000007fllu}, {0x0000000000000000llu}, {0x000000000000007fllu}},
		{{0x000000000000007fllu}, {0x000000000000007fllu}, {0x0000000000000000llu}},
}, std::integral_constant<unsigned, 7>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 16>
> pattern_xorassign16 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000001llu}},
		{{0x0000000000000000llu}, {0x000000000000ffffllu}, {0x000000000000ffffllu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x000000000000fffellu}, {0x000000000000ffffllu}},
		{{0x0000000000000667llu}, {0x000000000000bdd6llu}, {0x000000000000bbb1llu}},
		{{0x0000000000001641llu}, {0x000000000000972allu}, {0x000000000000816bllu}},
		{{0x0000000000003924llu}, {0x00000000000023b8llu}, {0x0000000000001a9cllu}},
		{{0x0000000000004668llu}, {0x0000000000003eb1llu}, {0x00000000000078d9llu}},
		{{0x000000000000a3b1llu}, {0x0000000000001c80llu}, {0x000000000000bf31llu}},
		{{0x000000000000ad3cllu}, {0x000000000000bd9cllu}, {0x00000000000010a0llu}},
		{{0x000000000000bc89llu}, {0x0000000000001a3dllu}, {0x000000000000a6b4llu}},
		{{0x000000000000e465llu}, {0x0000000000008b9dllu}, {0x0000000000006ff8llu}},
		{{0x000000000000fffellu}, {0x0000000000000001llu}, {0x000000000000ffffllu}},
		{{0x000000000000ffffllu}, {0x0000000000000000llu}, {0x000000000000ffffllu}},
		{{0x000000000000ffffllu}, {0x000000000000ffffllu}, {0x0000000000000000llu}},
}, std::integral_constant<unsigned, 16>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 63>
> pattern_xorassign63 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000001llu}},
		{{0x0000000000000000llu}, {0x7fffffffffffffffllu}, {0x7fffffffffffffffllu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0x7ffffffffffffffellu}, {0x7fffffffffffffffllu}},
		{{0x041174796c031199llu}, {0x0bfe34ad07a0ca6ellu}, {0x0fef40d46ba3dbf7llu}},
		{{0x0d1e8fd3bc8960a9llu}, {0x5ece3359ad3c2d6dllu}, {0x53d0bc8a11b54dc4llu}},
		{{0x0e4018bfa3b1799dllu}, {0x5eeb207d06671ad1llu}, {0x50ab38c2a5d6634cllu}},
		{{0x1dc7d50c37f8a88bllu}, {0x4d0ef322815ef6d1llu}, {0x50c9262eb6a65e5allu}},
		{{0x1f589dc846685257llu}, {0x11dc60f4392456dellu}, {0x0e84fd3c7f4c0489llu}},
		{{0x45ce921ae465e150llu}, {0x4b95423416419f82llu}, {0x0e5bd02ef2247ed2llu}},
		{{0x47d6e0d306cb0fb3llu}, {0x5ba687d832e70629llu}, {0x1c70670b342c099allu}},
		{{0x59c50446a65ed389llu}, {0x35b2d3528b8148f6llu}, {0x6c77d7142ddf9b7fllu}},
		{{0x7ffffffffffffffellu}, {0x0000000000000001llu}, {0x7fffffffffffffffllu}},
		{{0x7fffffffffffffffllu}, {0x0000000000000000llu}, {0x7fffffffffffffffllu}},
		{{0x7fffffffffffffffllu}, {0x7fffffffffffffffllu}, {0x0000000000000000llu}},
}, std::integral_constant<unsigned, 63>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 64>
> pattern_xorassign64 {{
		{{0x0000000000000000llu}, {0x0000000000000000llu}, {0x0000000000000000llu}},
		{{0x0000000000000000llu}, {0x0000000000000001llu}, {0x0000000000000001llu}},
		{{0x0000000000000000llu}, {0xffffffffffffffffllu}, {0xffffffffffffffffllu}},
		{{0x0000000000000001llu}, {0x0000000000000000llu}, {0x0000000000000001llu}},
		{{0x0000000000000001llu}, {0xfffffffffffffffellu}, {0xffffffffffffffffllu}},
		{{0x0822e8f36c031199llu}, {0x17fc695a07a0ca6ellu}, {0x1fde81a96ba3dbf7llu}},
		{{0x1a3d1fa7bc8960a9llu}, {0xbd9c66b3ad3c2d6dllu}, {0xa7a1791411b54dc4llu}},
		{{0x1c80317fa3b1799dllu}, {0xbdd640fb06671ad1llu}, {0xa1567184a5d6634cllu}},
		{{0x3b8faa1837f8a88bllu}, {0x9a1de644815ef6d1llu}, {0xa1924c5cb6a65e5allu}},
		{{0x3eb13b9046685257llu}, {0x23b8c1e9392456dellu}, {0x1d09fa797f4c0489llu}},
		{{0x8b9d2434e465e150llu}, {0x972a846916419f82llu}, {0x1cb7a05df2247ed2llu}},
		{{0x8fadc1a606cb0fb3llu}, {0xb74d0fb132e70629llu}, {0x38e0ce17342c099allu}},
		{{0xb38a088ca65ed389llu}, {0x6b65a6a48b8148f6llu}, {0xd8efae282ddf9b7fllu}},
		{{0xfffffffffffffffellu}, {0x0000000000000001llu}, {0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu}, {0x0000000000000000llu}, {0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu}, {0xffffffffffffffffllu}, {0x0000000000000000llu}},
}, std::integral_constant<unsigned, 64>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 127>
> pattern_xorassign127 {{
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0x0822e8f36c031199llu, 0x0bfe34ad07a0ca6ellu}, {0x3b8faa1837f8a88bllu, 0x4d0ef322815ef6d1llu}, {0x33ad42eb5bfbb912llu, 0x46f0c78f86fe3cbfllu}},
		{{0xc37459eef50bea63llu, 0x0d1539f6562b0f79llu}, {0x6142ea7d17be3111llu, 0x2df3094718c26797llu}, {0xa236b393e2b5db72llu, 0x20e630b14ee968eellu}},
		{{0x580d7b71d8f56413llu, 0x21dbd1d39a8dca03llu}, {0x0b1f9163ce9ff57fllu, 0x3ace6f33bacfb3d0llu}, {0x5312ea12166a916cllu, 0x1b15bee0204279d3llu}},
		{{0x72ff5d2a386ecbe0llu, 0x239bc0c896da1dacllu}, {0xde8a774bcf36d58bllu, 0x6120998501a9e71fllu}, {0xac752a61f7581e6bllu, 0x42bb594d9773fab3llu}},
		{{0x28df6ec4ce4a2bbdllu, 0x36183a88b2b9437allu}, {0x47229389571aa876llu, 0x1b8f66bd27cd8130llu}, {0x6ffdfd4d995083cbllu, 0x2d975c359574c24allu}},
		{{0x8fadc1a606cb0fb3llu, 0x5ba687d832e70629llu}, {0xb38a088ca65ed389llu, 0x35b2d3528b8148f6llu}, {0x3c27c92aa095dc3allu, 0x6e14548ab9664edfllu}},
		{{0x1a3d1fa7bc8960a9llu, 0x5ece3359ad3c2d6dllu}, {0x8b9d2434e465e150llu, 0x4b95423416419f82llu}, {0x91a03b9358ec81f9llu, 0x155b716dbb7db2efllu}},
		{{0x1c80317fa3b1799dllu, 0x5eeb207d06671ad1llu}, {0x3eb13b9046685257llu, 0x11dc60f4392456dellu}, {0x22310aefe5d92bcallu, 0x4f3740893f434c0fllu}},
		{{0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}},
}, std::integral_constant<unsigned, 127>{}};

static const std::pair<
	std::vector<BinaryPattern>,
	std::integral_constant<unsigned, 128>
> pattern_xorassign128 {{
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000001llu, 0x0000000000000000llu}},
		{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0x0822e8f36c031199llu, 0x17fc695a07a0ca6ellu}, {0x3b8faa1837f8a88bllu, 0x9a1de644815ef6d1llu}, {0x33ad42eb5bfbb912llu, 0x8de18f1e86fe3cbfllu}},
		{{0xc37459eef50bea63llu, 0x1a2a73ed562b0f79llu}, {0x6142ea7d17be3111llu, 0x5be6128e18c26797llu}, {0xa236b393e2b5db72llu, 0x41cc61634ee968eellu}},
		{{0x580d7b71d8f56413llu, 0x43b7a3a69a8dca03llu}, {0x0b1f9163ce9ff57fllu, 0x759cde66bacfb3d0llu}, {0x5312ea12166a916cllu, 0x362b7dc0204279d3llu}},
		{{0x72ff5d2a386ecbe0llu, 0x4737819096da1dacllu}, {0xde8a774bcf36d58bllu, 0xc241330b01a9e71fllu}, {0xac752a61f7581e6bllu, 0x8576b29b9773fab3llu}},
		{{0x28df6ec4ce4a2bbdllu, 0x6c307511b2b9437allu}, {0x47229389571aa876llu, 0x371ecd7b27cd8130llu}, {0x6ffdfd4d995083cbllu, 0x5b2eb86a9574c24allu}},
		{{0x8fadc1a606cb0fb3llu, 0xb74d0fb132e70629llu}, {0xb38a088ca65ed389llu, 0x6b65a6a48b8148f6llu}, {0x3c27c92aa095dc3allu, 0xdc28a915b9664edfllu}},
		{{0x1a3d1fa7bc8960a9llu, 0xbd9c66b3ad3c2d6dllu}, {0x8b9d2434e465e150llu, 0x972a846916419f82llu}, {0x91a03b9358ec81f9llu, 0x2ab6e2dabb7db2efllu}},
		{{0x1c80317fa3b1799dllu, 0xbdd640fb06671ad1llu}, {0x3eb13b9046685257llu, 0x23b8c1e9392456dellu}, {0x22310aefe5d92bcallu, 0x9e6e81123f434c0fllu}},
		{{0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
		{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}},
}, std::integral_constant<unsigned, 128>{}};

static auto pattern_addassign = std::tie(
	pattern_addassign7,
	pattern_addassign16,
	pattern_addassign63,
	pattern_addassign64,
	pattern_addassign127,
	pattern_addassign128
);
static auto pattern_subassign = std::tie(
	pattern_subassign7,
	pattern_subassign16,
	pattern_subassign63,
	pattern_subassign64,
	pattern_subassign127,
	pattern_subassign128
);
static auto pattern_mulassign = std::tie(
	pattern_mulassign7,
	pattern_mulassign16,
	pattern_mulassign63,
	pattern_mulassign64,
	pattern_mulassign127,
	pattern_mulassign128
);
static auto pattern_andassign = std::tie(
	pattern_andassign7,
	pattern_andassign16,
	pattern_andassign63,
	pattern_andassign64,
	pattern_andassign127,
	pattern_andassign128
);
static auto pattern_orassign = std::tie(
	pattern_orassign7,
	pattern_orassign16,
	pattern_orassign63,
	pattern_orassign64,
	pattern_orassign127,
	pattern_orassign128
);
static auto pattern_xorassign = std::tie(
	pattern_xorassign7,
	pattern_xorassign16,
	pattern_xorassign63,
	pattern_xorassign64,
	pattern_xorassign127,
	pattern_xorassign128
);
