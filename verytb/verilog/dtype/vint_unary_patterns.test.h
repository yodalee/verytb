#pragma once
// Direct include
#include "verilog/dtype/vint.h"
// C system headers
// C++ standard library headers
#include <utility>
#include <vector>
// Other libraries' .h files.
// Your project's .h files.

struct NegatePattern {
	std::vector<uint64_t> value1, value2;
};
struct ReduceAndPattern {
	std::vector<uint64_t> value;
	bool result;
};
using FlipPattern = NegatePattern;
using ReduceXorPattern = ReduceAndPattern;
using ReduceOrPattern = ReduceAndPattern;

static const std::pair<
	std::vector<NegatePattern>,
	std::integral_constant<unsigned, 7>
> pattern_negate7 {{
	{{0x0000000000000000llu}, {0x0000000000000000llu}},
	{{0x0000000000000001llu}, {0x000000000000007fllu}},
	{{0x0000000000000003llu}, {0x000000000000007dllu}},
	{{0x000000000000000ellu}, {0x0000000000000072llu}},
	{{0x0000000000000011llu}, {0x000000000000006fllu}},
	{{0x000000000000001cllu}, {0x0000000000000064llu}},
	{{0x000000000000001fllu}, {0x0000000000000061llu}},
	{{0x0000000000000023llu}, {0x000000000000005dllu}},
	{{0x0000000000000051llu}, {0x000000000000002fllu}},
	{{0x000000000000005ellu}, {0x0000000000000022llu}},
	{{0x000000000000007ellu}, {0x0000000000000002llu}},
	{{0x000000000000007fllu}, {0x0000000000000001llu}},
}, std::integral_constant<unsigned, 7>{}};

static const std::pair<
	std::vector<NegatePattern>,
	std::integral_constant<unsigned, 16>
> pattern_negate16 {{
	{{0x0000000000000000llu}, {0x0000000000000000llu}},
	{{0x0000000000000001llu}, {0x000000000000ffffllu}},
	{{0x0000000000000667llu}, {0x000000000000f999llu}},
	{{0x0000000000001c80llu}, {0x000000000000e380llu}},
	{{0x00000000000023b8llu}, {0x000000000000dc48llu}},
	{{0x0000000000003924llu}, {0x000000000000c6dcllu}},
	{{0x0000000000003eb1llu}, {0x000000000000c14fllu}},
	{{0x0000000000004668llu}, {0x000000000000b998llu}},
	{{0x000000000000a3b1llu}, {0x0000000000005c4fllu}},
	{{0x000000000000bdd6llu}, {0x000000000000422allu}},
	{{0x000000000000fffellu}, {0x0000000000000002llu}},
	{{0x000000000000ffffllu}, {0x0000000000000001llu}},
}, std::integral_constant<unsigned, 16>{}};

static const std::pair<
	std::vector<NegatePattern>,
	std::integral_constant<unsigned, 63>
> pattern_negate63 {{
	{{0x0000000000000000llu}, {0x0000000000000000llu}},
	{{0x0000000000000001llu}, {0x7fffffffffffffffllu}},
	{{0x0d1e8fd3bc8960a9llu}, {0x72e1702c43769f57llu}},
	{{0x0e4018bfa3b1799dllu}, {0x71bfe7405c4e8663llu}},
	{{0x11dc60f4392456dellu}, {0x6e239f0bc6dba922llu}},
	{{0x1f589dc846685257llu}, {0x60a76237b997ada9llu}},
	{{0x45ce921ae465e150llu}, {0x3a316de51b9a1eb0llu}},
	{{0x4b95423416419f82llu}, {0x346abdcbe9be607ellu}},
	{{0x5ece3359ad3c2d6dllu}, {0x2131cca652c3d293llu}},
	{{0x5eeb207d06671ad1llu}, {0x2114df82f998e52fllu}},
	{{0x7ffffffffffffffellu}, {0x0000000000000002llu}},
	{{0x7fffffffffffffffllu}, {0x0000000000000001llu}},
}, std::integral_constant<unsigned, 63>{}};

static const std::pair<
	std::vector<NegatePattern>,
	std::integral_constant<unsigned, 64>
> pattern_negate64 {{
	{{0x0000000000000000llu}, {0x0000000000000000llu}},
	{{0x0000000000000001llu}, {0xffffffffffffffffllu}},
	{{0x1a3d1fa7bc8960a9llu}, {0xe5c2e05843769f57llu}},
	{{0x1c80317fa3b1799dllu}, {0xe37fce805c4e8663llu}},
	{{0x23b8c1e9392456dellu}, {0xdc473e16c6dba922llu}},
	{{0x3eb13b9046685257llu}, {0xc14ec46fb997ada9llu}},
	{{0x8b9d2434e465e150llu}, {0x7462dbcb1b9a1eb0llu}},
	{{0x972a846916419f82llu}, {0x68d57b96e9be607ellu}},
	{{0xbd9c66b3ad3c2d6dllu}, {0x4263994c52c3d293llu}},
	{{0xbdd640fb06671ad1llu}, {0x4229bf04f998e52fllu}},
	{{0xfffffffffffffffellu}, {0x0000000000000002llu}},
	{{0xffffffffffffffffllu}, {0x0000000000000001llu}},
}, std::integral_constant<unsigned, 64>{}};

static const std::pair<
	std::vector<NegatePattern>,
	std::integral_constant<unsigned, 127>
> pattern_negate127 {{
	{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
	{{0x0000000000000001llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
	{{0x0822e8f36c031199llu, 0x0bfe34ad07a0ca6ellu}, {0xf7dd170c93fcee67llu, 0x7401cb52f85f3591llu}},
	{{0x3eb13b9046685257llu, 0x11dc60f4392456dellu}, {0xc14ec46fb997ada9llu, 0x6e239f0bc6dba921llu}},
	{{0xb38a088ca65ed389llu, 0x35b2d3528b8148f6llu}, {0x4c75f77359a12c77llu, 0x4a4d2cad747eb709llu}},
	{{0x8b9d2434e465e150llu, 0x4b95423416419f82llu}, {0x7462dbcb1b9a1eb0llu, 0x346abdcbe9be607dllu}},
	{{0x3b8faa1837f8a88bllu, 0x4d0ef322815ef6d1llu}, {0xc47055e7c8075775llu, 0x32f10cdd7ea1092ellu}},
	{{0x8fadc1a606cb0fb3llu, 0x5ba687d832e70629llu}, {0x70523e59f934f04dllu, 0x24597827cd18f9d6llu}},
	{{0x1a3d1fa7bc8960a9llu, 0x5ece3359ad3c2d6dllu}, {0xe5c2e05843769f57llu, 0x2131cca652c3d292llu}},
	{{0x1c80317fa3b1799dllu, 0x5eeb207d06671ad1llu}, {0xe37fce805c4e8663llu, 0x2114df82f998e52ellu}},
	{{0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0x0000000000000002llu, 0x0000000000000000llu}},
	{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}},
}, std::integral_constant<unsigned, 127>{}};

static const std::pair<
	std::vector<NegatePattern>,
	std::integral_constant<unsigned, 128>
> pattern_negate128 {{
	{{0x0000000000000000llu, 0x0000000000000000llu}, {0x0000000000000000llu, 0x0000000000000000llu}},
	{{0x0000000000000001llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
	{{0x0822e8f36c031199llu, 0x17fc695a07a0ca6ellu}, {0xf7dd170c93fcee67llu, 0xe80396a5f85f3591llu}},
	{{0x3eb13b9046685257llu, 0x23b8c1e9392456dellu}, {0xc14ec46fb997ada9llu, 0xdc473e16c6dba921llu}},
	{{0xb38a088ca65ed389llu, 0x6b65a6a48b8148f6llu}, {0x4c75f77359a12c77llu, 0x949a595b747eb709llu}},
	{{0x8b9d2434e465e150llu, 0x972a846916419f82llu}, {0x7462dbcb1b9a1eb0llu, 0x68d57b96e9be607dllu}},
	{{0x3b8faa1837f8a88bllu, 0x9a1de644815ef6d1llu}, {0xc47055e7c8075775llu, 0x65e219bb7ea1092ellu}},
	{{0x8fadc1a606cb0fb3llu, 0xb74d0fb132e70629llu}, {0x70523e59f934f04dllu, 0x48b2f04ecd18f9d6llu}},
	{{0x1a3d1fa7bc8960a9llu, 0xbd9c66b3ad3c2d6dllu}, {0xe5c2e05843769f57llu, 0x4263994c52c3d292llu}},
	{{0x1c80317fa3b1799dllu, 0xbdd640fb06671ad1llu}, {0xe37fce805c4e8663llu, 0x4229bf04f998e52ellu}},
	{{0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0x0000000000000002llu, 0x0000000000000000llu}},
	{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}},
}, std::integral_constant<unsigned, 128>{}};

static const std::pair<
	std::vector<NegatePattern>,
	std::integral_constant<unsigned, 7>
> pattern_flip7 {{
	{{0x0000000000000000llu}, {0x000000000000007fllu}},
	{{0x0000000000000001llu}, {0x000000000000007ellu}},
	{{0x0000000000000004llu}, {0x000000000000007bllu}},
	{{0x0000000000000012llu}, {0x000000000000006dllu}},
	{{0x0000000000000024llu}, {0x000000000000005bllu}},
	{{0x000000000000002fllu}, {0x0000000000000050llu}},
	{{0x000000000000003bllu}, {0x0000000000000044llu}},
	{{0x0000000000000059llu}, {0x0000000000000026llu}},
	{{0x0000000000000061llu}, {0x000000000000001ellu}},
	{{0x000000000000007allu}, {0x0000000000000005llu}},
	{{0x000000000000007ellu}, {0x0000000000000001llu}},
	{{0x000000000000007fllu}, {0x0000000000000000llu}},
}, std::integral_constant<unsigned, 7>{}};

static const std::pair<
	std::vector<NegatePattern>,
	std::integral_constant<unsigned, 16>
> pattern_flip16 {{
	{{0x0000000000000000llu}, {0x000000000000ffffllu}},
	{{0x0000000000000001llu}, {0x000000000000fffellu}},
	{{0x00000000000009dellu}, {0x000000000000f621llu}},
	{{0x00000000000024d8llu}, {0x000000000000db27llu}},
	{{0x000000000000493cllu}, {0x000000000000b6c3llu}},
	{{0x0000000000005eb0llu}, {0x000000000000a14fllu}},
	{{0x0000000000007668llu}, {0x0000000000008997llu}},
	{{0x000000000000b23bllu}, {0x0000000000004dc4llu}},
	{{0x000000000000c33fllu}, {0x0000000000003cc0llu}},
	{{0x000000000000f59bllu}, {0x0000000000000a64llu}},
	{{0x000000000000fffellu}, {0x0000000000000001llu}},
	{{0x000000000000ffffllu}, {0x0000000000000000llu}},
}, std::integral_constant<unsigned, 16>{}};

static const std::pair<
	std::vector<NegatePattern>,
	std::integral_constant<unsigned, 63>
> pattern_flip63 {{
	{{0x0000000000000000llu}, {0x7fffffffffffffffllu}},
	{{0x0000000000000001llu}, {0x7ffffffffffffffellu}},
	{{0x0c530c32cafedacfllu}, {0x73acf3cd35012530llu}},
	{{0x249e680b09de8895llu}, {0x5b6197f4f621776allu}},
	{{0x2f58229076688387llu}, {0x50a7dd6f89977c78llu}},
	{{0x4ca5bd2b74043590llu}, {0x335a42d48bfbca6fllu}},
	{{0x4df354757f8ec4c2llu}, {0x320cab8a80713b3dllu}},
	{{0x59666fd3abf10ac2llu}, {0x2699902c540ef53dllu}},
	{{0x619fa2c2b23bc1d8llu}, {0x1e605d3d4dc43e27llu}},
	{{0x7acdd3cc24d8cea5llu}, {0x05322c33db27315allu}},
	{{0x7ffffffffffffffellu}, {0x0000000000000001llu}},
	{{0x7fffffffffffffffllu}, {0x0000000000000000llu}},
}, std::integral_constant<unsigned, 63>{}};

static const std::pair<
	std::vector<NegatePattern>,
	std::integral_constant<unsigned, 64>
> pattern_flip64 {{
	{{0x0000000000000000llu}, {0xffffffffffffffffllu}},
	{{0x0000000000000001llu}, {0xfffffffffffffffellu}},
	{{0x18a61865cafedacfllu}, {0xe759e79a35012530llu}},
	{{0x493cd01609de8895llu}, {0xb6c32fe9f621776allu}},
	{{0x5eb0452176688387llu}, {0xa14fbade89977c78llu}},
	{{0x994b7a5674043590llu}, {0x66b485a98bfbca6fllu}},
	{{0x9be6a8ea7f8ec4c2llu}, {0x6419571580713b3dllu}},
	{{0xb2ccdfa7abf10ac2llu}, {0x4d332058540ef53dllu}},
	{{0xc33f4584b23bc1d8llu}, {0x3cc0ba7b4dc43e27llu}},
	{{0xf59ba79924d8cea5llu}, {0x0a645866db27315allu}},
	{{0xfffffffffffffffellu}, {0x0000000000000001llu}},
	{{0xffffffffffffffffllu}, {0x0000000000000000llu}},
}, std::integral_constant<unsigned, 64>{}};

static const std::pair<
	std::vector<NegatePattern>,
	std::integral_constant<unsigned, 127>
> pattern_flip127 {{
	{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0x7fffffffffffffffllu}},
	{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0x7fffffffffffffffllu}},
	{{0x64d8f3636f1f16f1llu, 0x07634e9b2d1aa9eallu}, {0x9b270c9c90e0e90ellu, 0x789cb164d2e55615llu}},
	{{0xb2ccdfa7abf10ac2llu, 0x0c530c32cafedacfllu}, {0x4d332058540ef53dllu, 0x73acf3cd35012530llu}},
	{{0xf59ba79924d8cea5llu, 0x2f58229076688387llu}, {0x0a645866db27315allu, 0x50a7dd6f89977c78llu}},
	{{0x839aa6b004e77af5llu, 0x49ceb0ee6eb108e2llu}, {0x7c65594ffb18850allu, 0x36314f11914ef71dllu}},
	{{0x994b7a5674043590llu, 0x4df354757f8ec4c2llu}, {0x66b485a98bfbca6fllu, 0x320cab8a80713b3dllu}},
	{{0x493cd01609de8895llu, 0x619fa2c2b23bc1d8llu}, {0xb6c32fe9f621776allu, 0x1e605d3d4dc43e27llu}},
	{{0x9fdfe1685f53f26cllu, 0x793aa0c6da2f966ellu}, {0x60201e97a0ac0d93llu, 0x06c55f3925d06991llu}},
	{{0xe2f234308c072307llu, 0x79b15b84c15c71bfllu}, {0x1d0dcbcf73f8dcf8llu, 0x064ea47b3ea38e40llu}},
	{{0xfffffffffffffffellu, 0x7fffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}},
	{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}},
}, std::integral_constant<unsigned, 127>{}};

static const std::pair<
	std::vector<NegatePattern>,
	std::integral_constant<unsigned, 128>
> pattern_flip128 {{
	{{0x0000000000000000llu, 0x0000000000000000llu}, {0xffffffffffffffffllu, 0xffffffffffffffffllu}},
	{{0x0000000000000001llu, 0x0000000000000000llu}, {0xfffffffffffffffellu, 0xffffffffffffffffllu}},
	{{0x64d8f3636f1f16f1llu, 0x0ec69d372d1aa9eallu}, {0x9b270c9c90e0e90ellu, 0xf13962c8d2e55615llu}},
	{{0xb2ccdfa7abf10ac2llu, 0x18a61865cafedacfllu}, {0x4d332058540ef53dllu, 0xe759e79a35012530llu}},
	{{0xf59ba79924d8cea5llu, 0x5eb0452176688387llu}, {0x0a645866db27315allu, 0xa14fbade89977c78llu}},
	{{0x839aa6b004e77af5llu, 0x939d61dc6eb108e2llu}, {0x7c65594ffb18850allu, 0x6c629e23914ef71dllu}},
	{{0x994b7a5674043590llu, 0x9be6a8ea7f8ec4c2llu}, {0x66b485a98bfbca6fllu, 0x6419571580713b3dllu}},
	{{0x493cd01609de8895llu, 0xc33f4584b23bc1d8llu}, {0xb6c32fe9f621776allu, 0x3cc0ba7b4dc43e27llu}},
	{{0x9fdfe1685f53f26cllu, 0xf275418cda2f966ellu}, {0x60201e97a0ac0d93llu, 0x0d8abe7325d06991llu}},
	{{0xe2f234308c072307llu, 0xf362b708c15c71bfllu}, {0x1d0dcbcf73f8dcf8llu, 0x0c9d48f73ea38e40llu}},
	{{0xfffffffffffffffellu, 0xffffffffffffffffllu}, {0x0000000000000001llu, 0x0000000000000000llu}},
	{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, {0x0000000000000000llu, 0x0000000000000000llu}},
}, std::integral_constant<unsigned, 128>{}};

static const std::pair<
	std::vector<ReduceAndPattern>,
	std::integral_constant<unsigned, 7>
> pattern_reduceand7 {{
	{{0x0000000000000000llu}, 0},
	{{0x0000000000000001llu}, 0},
	{{0x0000000000000003llu}, 0},
	{{0x000000000000000ellu}, 0},
	{{0x0000000000000011llu}, 0},
	{{0x000000000000001cllu}, 0},
	{{0x000000000000001fllu}, 0},
	{{0x0000000000000023llu}, 0},
	{{0x0000000000000051llu}, 0},
	{{0x000000000000005ellu}, 0},
	{{0x000000000000007ellu}, 0},
	{{0x000000000000007fllu}, 1},
}, std::integral_constant<unsigned, 7>{}};

static const std::pair<
	std::vector<ReduceAndPattern>,
	std::integral_constant<unsigned, 16>
> pattern_reduceand16 {{
	{{0x0000000000000000llu}, 0},
	{{0x0000000000000001llu}, 0},
	{{0x0000000000000667llu}, 0},
	{{0x0000000000001c80llu}, 0},
	{{0x00000000000023b8llu}, 0},
	{{0x0000000000003924llu}, 0},
	{{0x0000000000003eb1llu}, 0},
	{{0x0000000000004668llu}, 0},
	{{0x000000000000a3b1llu}, 0},
	{{0x000000000000bdd6llu}, 0},
	{{0x000000000000fffellu}, 0},
	{{0x000000000000ffffllu}, 1},
}, std::integral_constant<unsigned, 16>{}};

static const std::pair<
	std::vector<ReduceAndPattern>,
	std::integral_constant<unsigned, 63>
> pattern_reduceand63 {{
	{{0x0000000000000000llu}, 0},
	{{0x0000000000000001llu}, 0},
	{{0x0d1e8fd3bc8960a9llu}, 0},
	{{0x0e4018bfa3b1799dllu}, 0},
	{{0x11dc60f4392456dellu}, 0},
	{{0x1f589dc846685257llu}, 0},
	{{0x45ce921ae465e150llu}, 0},
	{{0x4b95423416419f82llu}, 0},
	{{0x5ece3359ad3c2d6dllu}, 0},
	{{0x5eeb207d06671ad1llu}, 0},
	{{0x7ffffffffffffffellu}, 0},
	{{0x7fffffffffffffffllu}, 1},
}, std::integral_constant<unsigned, 63>{}};

static const std::pair<
	std::vector<ReduceAndPattern>,
	std::integral_constant<unsigned, 64>
> pattern_reduceand64 {{
	{{0x0000000000000000llu}, 0},
	{{0x0000000000000001llu}, 0},
	{{0x1a3d1fa7bc8960a9llu}, 0},
	{{0x1c80317fa3b1799dllu}, 0},
	{{0x23b8c1e9392456dellu}, 0},
	{{0x3eb13b9046685257llu}, 0},
	{{0x8b9d2434e465e150llu}, 0},
	{{0x972a846916419f82llu}, 0},
	{{0xbd9c66b3ad3c2d6dllu}, 0},
	{{0xbdd640fb06671ad1llu}, 0},
	{{0xfffffffffffffffellu}, 0},
	{{0xffffffffffffffffllu}, 1},
}, std::integral_constant<unsigned, 64>{}};

static const std::pair<
	std::vector<ReduceAndPattern>,
	std::integral_constant<unsigned, 127>
> pattern_reduceand127 {{
	{{0x0000000000000000llu, 0x0000000000000000llu}, 0},
	{{0x0000000000000001llu, 0x0000000000000000llu}, 0},
	{{0x0822e8f36c031199llu, 0x0bfe34ad07a0ca6ellu}, 0},
	{{0x3eb13b9046685257llu, 0x11dc60f4392456dellu}, 0},
	{{0xb38a088ca65ed389llu, 0x35b2d3528b8148f6llu}, 0},
	{{0x8b9d2434e465e150llu, 0x4b95423416419f82llu}, 0},
	{{0x3b8faa1837f8a88bllu, 0x4d0ef322815ef6d1llu}, 0},
	{{0x8fadc1a606cb0fb3llu, 0x5ba687d832e70629llu}, 0},
	{{0x1a3d1fa7bc8960a9llu, 0x5ece3359ad3c2d6dllu}, 0},
	{{0x1c80317fa3b1799dllu, 0x5eeb207d06671ad1llu}, 0},
	{{0xfffffffffffffffellu, 0x7fffffffffffffffllu}, 0},
	{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, 1},
}, std::integral_constant<unsigned, 127>{}};

static const std::pair<
	std::vector<ReduceAndPattern>,
	std::integral_constant<unsigned, 128>
> pattern_reduceand128 {{
	{{0x0000000000000000llu, 0x0000000000000000llu}, 0},
	{{0x0000000000000001llu, 0x0000000000000000llu}, 0},
	{{0x0822e8f36c031199llu, 0x17fc695a07a0ca6ellu}, 0},
	{{0x3eb13b9046685257llu, 0x23b8c1e9392456dellu}, 0},
	{{0xb38a088ca65ed389llu, 0x6b65a6a48b8148f6llu}, 0},
	{{0x8b9d2434e465e150llu, 0x972a846916419f82llu}, 0},
	{{0x3b8faa1837f8a88bllu, 0x9a1de644815ef6d1llu}, 0},
	{{0x8fadc1a606cb0fb3llu, 0xb74d0fb132e70629llu}, 0},
	{{0x1a3d1fa7bc8960a9llu, 0xbd9c66b3ad3c2d6dllu}, 0},
	{{0x1c80317fa3b1799dllu, 0xbdd640fb06671ad1llu}, 0},
	{{0xfffffffffffffffellu, 0xffffffffffffffffllu}, 0},
	{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, 1},
}, std::integral_constant<unsigned, 128>{}};

static const std::pair<
	std::vector<ReduceOrPattern>,
	std::integral_constant<unsigned, 7>
> pattern_reduceor7 {{
	{{0x0000000000000000llu}, 0},
	{{0x0000000000000001llu}, 1},
	{{0x0000000000000003llu}, 1},
	{{0x000000000000000ellu}, 1},
	{{0x0000000000000011llu}, 1},
	{{0x000000000000001cllu}, 1},
	{{0x000000000000001fllu}, 1},
	{{0x0000000000000023llu}, 1},
	{{0x0000000000000051llu}, 1},
	{{0x000000000000005ellu}, 1},
	{{0x000000000000007ellu}, 1},
	{{0x000000000000007fllu}, 1},
}, std::integral_constant<unsigned, 7>{}};

static const std::pair<
	std::vector<ReduceOrPattern>,
	std::integral_constant<unsigned, 16>
> pattern_reduceor16 {{
	{{0x0000000000000000llu}, 0},
	{{0x0000000000000001llu}, 1},
	{{0x0000000000000667llu}, 1},
	{{0x0000000000001c80llu}, 1},
	{{0x00000000000023b8llu}, 1},
	{{0x0000000000003924llu}, 1},
	{{0x0000000000003eb1llu}, 1},
	{{0x0000000000004668llu}, 1},
	{{0x000000000000a3b1llu}, 1},
	{{0x000000000000bdd6llu}, 1},
	{{0x000000000000fffellu}, 1},
	{{0x000000000000ffffllu}, 1},
}, std::integral_constant<unsigned, 16>{}};

static const std::pair<
	std::vector<ReduceOrPattern>,
	std::integral_constant<unsigned, 63>
> pattern_reduceor63 {{
	{{0x0000000000000000llu}, 0},
	{{0x0000000000000001llu}, 1},
	{{0x0d1e8fd3bc8960a9llu}, 1},
	{{0x0e4018bfa3b1799dllu}, 1},
	{{0x11dc60f4392456dellu}, 1},
	{{0x1f589dc846685257llu}, 1},
	{{0x45ce921ae465e150llu}, 1},
	{{0x4b95423416419f82llu}, 1},
	{{0x5ece3359ad3c2d6dllu}, 1},
	{{0x5eeb207d06671ad1llu}, 1},
	{{0x7ffffffffffffffellu}, 1},
	{{0x7fffffffffffffffllu}, 1},
}, std::integral_constant<unsigned, 63>{}};

static const std::pair<
	std::vector<ReduceOrPattern>,
	std::integral_constant<unsigned, 64>
> pattern_reduceor64 {{
	{{0x0000000000000000llu}, 0},
	{{0x0000000000000001llu}, 1},
	{{0x1a3d1fa7bc8960a9llu}, 1},
	{{0x1c80317fa3b1799dllu}, 1},
	{{0x23b8c1e9392456dellu}, 1},
	{{0x3eb13b9046685257llu}, 1},
	{{0x8b9d2434e465e150llu}, 1},
	{{0x972a846916419f82llu}, 1},
	{{0xbd9c66b3ad3c2d6dllu}, 1},
	{{0xbdd640fb06671ad1llu}, 1},
	{{0xfffffffffffffffellu}, 1},
	{{0xffffffffffffffffllu}, 1},
}, std::integral_constant<unsigned, 64>{}};

static const std::pair<
	std::vector<ReduceOrPattern>,
	std::integral_constant<unsigned, 127>
> pattern_reduceor127 {{
	{{0x0000000000000000llu, 0x0000000000000000llu}, 0},
	{{0x0000000000000001llu, 0x0000000000000000llu}, 1},
	{{0x0822e8f36c031199llu, 0x0bfe34ad07a0ca6ellu}, 1},
	{{0x3eb13b9046685257llu, 0x11dc60f4392456dellu}, 1},
	{{0xb38a088ca65ed389llu, 0x35b2d3528b8148f6llu}, 1},
	{{0x8b9d2434e465e150llu, 0x4b95423416419f82llu}, 1},
	{{0x3b8faa1837f8a88bllu, 0x4d0ef322815ef6d1llu}, 1},
	{{0x8fadc1a606cb0fb3llu, 0x5ba687d832e70629llu}, 1},
	{{0x1a3d1fa7bc8960a9llu, 0x5ece3359ad3c2d6dllu}, 1},
	{{0x1c80317fa3b1799dllu, 0x5eeb207d06671ad1llu}, 1},
	{{0xfffffffffffffffellu, 0x7fffffffffffffffllu}, 1},
	{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, 1},
}, std::integral_constant<unsigned, 127>{}};

static const std::pair<
	std::vector<ReduceOrPattern>,
	std::integral_constant<unsigned, 128>
> pattern_reduceor128 {{
	{{0x0000000000000000llu, 0x0000000000000000llu}, 0},
	{{0x0000000000000001llu, 0x0000000000000000llu}, 1},
	{{0x0822e8f36c031199llu, 0x17fc695a07a0ca6ellu}, 1},
	{{0x3eb13b9046685257llu, 0x23b8c1e9392456dellu}, 1},
	{{0xb38a088ca65ed389llu, 0x6b65a6a48b8148f6llu}, 1},
	{{0x8b9d2434e465e150llu, 0x972a846916419f82llu}, 1},
	{{0x3b8faa1837f8a88bllu, 0x9a1de644815ef6d1llu}, 1},
	{{0x8fadc1a606cb0fb3llu, 0xb74d0fb132e70629llu}, 1},
	{{0x1a3d1fa7bc8960a9llu, 0xbd9c66b3ad3c2d6dllu}, 1},
	{{0x1c80317fa3b1799dllu, 0xbdd640fb06671ad1llu}, 1},
	{{0xfffffffffffffffellu, 0xffffffffffffffffllu}, 1},
	{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, 1},
}, std::integral_constant<unsigned, 128>{}};

static const std::pair<
	std::vector<ReduceXorPattern>,
	std::integral_constant<unsigned, 7>
> pattern_reducexor7 {{
	{{0x0000000000000000llu}, 0},
	{{0x0000000000000001llu}, 1},
	{{0x0000000000000003llu}, 0},
	{{0x000000000000000ellu}, 1},
	{{0x0000000000000011llu}, 0},
	{{0x000000000000001cllu}, 1},
	{{0x000000000000001fllu}, 1},
	{{0x0000000000000023llu}, 1},
	{{0x0000000000000051llu}, 1},
	{{0x000000000000005ellu}, 1},
	{{0x000000000000007ellu}, 0},
	{{0x000000000000007fllu}, 1},
}, std::integral_constant<unsigned, 7>{}};

static const std::pair<
	std::vector<ReduceXorPattern>,
	std::integral_constant<unsigned, 16>
> pattern_reducexor16 {{
	{{0x0000000000000000llu}, 0},
	{{0x0000000000000001llu}, 1},
	{{0x0000000000000667llu}, 1},
	{{0x0000000000001c80llu}, 0},
	{{0x00000000000023b8llu}, 1},
	{{0x0000000000003924llu}, 0},
	{{0x0000000000003eb1llu}, 1},
	{{0x0000000000004668llu}, 0},
	{{0x000000000000a3b1llu}, 0},
	{{0x000000000000bdd6llu}, 1},
	{{0x000000000000fffellu}, 1},
	{{0x000000000000ffffllu}, 0},
}, std::integral_constant<unsigned, 16>{}};

static const std::pair<
	std::vector<ReduceXorPattern>,
	std::integral_constant<unsigned, 63>
> pattern_reducexor63 {{
	{{0x0000000000000000llu}, 0},
	{{0x0000000000000001llu}, 1},
	{{0x0d1e8fd3bc8960a9llu}, 1},
	{{0x0e4018bfa3b1799dllu}, 1},
	{{0x11dc60f4392456dellu}, 0},
	{{0x1f589dc846685257llu}, 0},
	{{0x45ce921ae465e150llu}, 0},
	{{0x4b95423416419f82llu}, 0},
	{{0x5ece3359ad3c2d6dllu}, 0},
	{{0x5eeb207d06671ad1llu}, 0},
	{{0x7ffffffffffffffellu}, 0},
	{{0x7fffffffffffffffllu}, 1},
}, std::integral_constant<unsigned, 63>{}};

static const std::pair<
	std::vector<ReduceXorPattern>,
	std::integral_constant<unsigned, 64>
> pattern_reducexor64 {{
	{{0x0000000000000000llu}, 0},
	{{0x0000000000000001llu}, 1},
	{{0x1a3d1fa7bc8960a9llu}, 0},
	{{0x1c80317fa3b1799dllu}, 0},
	{{0x23b8c1e9392456dellu}, 1},
	{{0x3eb13b9046685257llu}, 0},
	{{0x8b9d2434e465e150llu}, 0},
	{{0x972a846916419f82llu}, 1},
	{{0xbd9c66b3ad3c2d6dllu}, 1},
	{{0xbdd640fb06671ad1llu}, 1},
	{{0xfffffffffffffffellu}, 1},
	{{0xffffffffffffffffllu}, 0},
}, std::integral_constant<unsigned, 64>{}};

static const std::pair<
	std::vector<ReduceXorPattern>,
	std::integral_constant<unsigned, 127>
> pattern_reducexor127 {{
	{{0x0000000000000000llu, 0x0000000000000000llu}, 0},
	{{0x0000000000000001llu, 0x0000000000000000llu}, 1},
	{{0x0822e8f36c031199llu, 0x0bfe34ad07a0ca6ellu}, 1},
	{{0x3eb13b9046685257llu, 0x11dc60f4392456dellu}, 0},
	{{0xb38a088ca65ed389llu, 0x35b2d3528b8148f6llu}, 1},
	{{0x8b9d2434e465e150llu, 0x4b95423416419f82llu}, 0},
	{{0x3b8faa1837f8a88bllu, 0x4d0ef322815ef6d1llu}, 1},
	{{0x8fadc1a606cb0fb3llu, 0x5ba687d832e70629llu}, 0},
	{{0x1a3d1fa7bc8960a9llu, 0x5ece3359ad3c2d6dllu}, 0},
	{{0x1c80317fa3b1799dllu, 0x5eeb207d06671ad1llu}, 0},
	{{0xfffffffffffffffellu, 0x7fffffffffffffffllu}, 0},
	{{0xffffffffffffffffllu, 0x7fffffffffffffffllu}, 1},
}, std::integral_constant<unsigned, 127>{}};

static const std::pair<
	std::vector<ReduceXorPattern>,
	std::integral_constant<unsigned, 128>
> pattern_reducexor128 {{
	{{0x0000000000000000llu, 0x0000000000000000llu}, 0},
	{{0x0000000000000001llu, 0x0000000000000000llu}, 1},
	{{0x0822e8f36c031199llu, 0x17fc695a07a0ca6ellu}, 1},
	{{0x3eb13b9046685257llu, 0x23b8c1e9392456dellu}, 1},
	{{0xb38a088ca65ed389llu, 0x6b65a6a48b8148f6llu}, 1},
	{{0x8b9d2434e465e150llu, 0x972a846916419f82llu}, 1},
	{{0x3b8faa1837f8a88bllu, 0x9a1de644815ef6d1llu}, 1},
	{{0x8fadc1a606cb0fb3llu, 0xb74d0fb132e70629llu}, 1},
	{{0x1a3d1fa7bc8960a9llu, 0xbd9c66b3ad3c2d6dllu}, 1},
	{{0x1c80317fa3b1799dllu, 0xbdd640fb06671ad1llu}, 1},
	{{0xfffffffffffffffellu, 0xffffffffffffffffllu}, 1},
	{{0xffffffffffffffffllu, 0xffffffffffffffffllu}, 0},
}, std::integral_constant<unsigned, 128>{}};

static auto pattern_negate = std::tie(
	pattern_negate7,
	pattern_negate16,
	pattern_negate63,
	pattern_negate64,
	pattern_negate127,
	pattern_negate128
);
static auto pattern_flip = std::tie(
	pattern_flip7,
	pattern_flip16,
	pattern_flip63,
	pattern_flip64,
	pattern_flip127,
	pattern_flip128
);
static auto pattern_reduceand = std::tie(
	pattern_reduceand7,
	pattern_reduceand16,
	pattern_reduceand63,
	pattern_reduceand64,
	pattern_reduceand127,
	pattern_reduceand128
);
static auto pattern_reduceor = std::tie(
	pattern_reduceor7,
	pattern_reduceor16,
	pattern_reduceor63,
	pattern_reduceor64,
	pattern_reduceor127,
	pattern_reduceor128
);
static auto pattern_reducexor = std::tie(
	pattern_reducexor7,
	pattern_reducexor16,
	pattern_reducexor63,
	pattern_reducexor64,
	pattern_reducexor127,
	pattern_reducexor128
);
