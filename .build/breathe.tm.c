#line 1 "/Users/andrewdong/Documents/2025/Recurse/bruce_stuff/breathe/breathe.tm"
#define __SOURCE_FILE__ "/Users/andrewdong/Documents/2025/Recurse/bruce_stuff/breathe/breathe.tm"
#include <tomo/tomo.h>
#include "breathe.tm.h"





#line 3
public void _$breathe$sleep_with_bar(Text_t _$phase, Int_t _$duration) {

#line 5
Text_t _$symbol = ((Text_t)Text$from_str("\xE2""\x80""\xA2"""));

#line 7
if (generic_equal(stack(_$phase), stack(Text("Inhale")), &Text$info))
#line 7
{

#line 8
_$symbol = ((Text_t)Text$from_str("\xE2""\x86""\x91"""));

}


#line 9
if (generic_equal(stack(_$phase), stack(Text("Hold")), &Text$info))
#line 9
{

#line 10
_$symbol = ((Text_t)Text$from_str("\xE2""\x86""\x92"""));

}


#line 11
if (generic_equal(stack(_$phase), stack(Text("Exhale")), &Text$info))
#line 11
{

#line 12
_$symbol = ((Text_t)Text$from_str("\xE2""\x86""\x93"""));

}


#line 14
(void)say(Text(""), yes);

#line 15
(void)say(Text$concat(Text$concat(Text$concat(Text$concat(Text("  "), _$phase), Text(" (")), Int$as_text(stack(_$duration), no, &Int$info)), Text("s)")), yes);

#line 16
(void)say(Text("  "), yes);

#line 17
for (Int_t _$i = I(1), max_$i = _$duration; Int$compare_value(_$i, max_$i) <= 0; _$i = Int$plus(_$i, I(1))) {
	
#line 18
(void)say(_$symbol, yes);

#line 19
(void)sleep_num(N64(1));
}



#line 20
(void)say(Text(""), yes);
}


#line 22
public void _$breathe$main(Int_t _$inhale_time, Int_t _$hold_time, Int_t _$exhale_time, Int_t _$cycles) {

#line 23
(void)say(Text("===================================="), yes);

#line 24
(void)say(((Text_t)Text$from_str("  \xF0""\x9F""\xA7""\x98"" BREATHE \xF0""\x9F""\xA7""\x98""")), yes);

#line 25
(void)say(Text("===================================="), yes);

#line 26
(void)say(Text$concat(Text$concat(Text$concat(Text$concat(Text("  Inhale: "), Int$as_text(stack(_$inhale_time), no, &Int$info)), Text("s | Hold: ")), Int$as_text(stack(_$hold_time), no, &Int$info)), Text("s")), yes);

#line 27
(void)say(Text$concat(Text$concat(Text$concat(Text("  Exhale: "), Int$as_text(stack(_$exhale_time), no, &Int$info)), Text("s | Cycles: ")), Int$as_text(stack(_$cycles), no, &Int$info)), yes);

#line 28
(void)say(Text("===================================="), yes);

#line 30
for (Int_t _$i = I(1), max_$i = _$cycles; Int$compare_value(_$i, max_$i) <= 0; _$i = Int$plus(_$i, I(1))) {
	
#line 31
(void)say(Text(""), yes);

#line 32
(void)say(Text("------------------------------------"), yes);

#line 33
(void)say(Text$concat(Text$concat(Text$concat(Text("  CYCLE "), Int$as_text(stack(_$i), no, &Int$info)), Text(" of ")), Int$as_text(stack(_$cycles), no, &Int$info)), yes);

#line 34
(void)say(Text("------------------------------------"), yes);

#line 35
(void)_$breathe$sleep_with_bar(Text("Inhale"), _$inhale_time);

#line 36
(void)_$breathe$sleep_with_bar(Text("Hold"), _$hold_time);

#line 37
(void)_$breathe$sleep_with_bar(Text("Exhale"), _$exhale_time);

#line 38
(void)_$breathe$sleep_with_bar(Text("Hold"), _$hold_time);
}



#line 40
(void)say(Text(""), yes);

#line 41
(void)say(Text("===================================="), yes);

#line 42
(void)say(((Text_t)Text$from_str("  \xE2""\x9C""\x85"" ")), yes);

#line 43
(void)say(Text("===================================="), yes);
}

public void _$breathe$$initialize(void) {
static bool initialized = false;
if (initialized) return;
initialized = true;
register_function(_$breathe$sleep_with_bar, Text("breathe.tm"), 3, Text("func sleep_with_bar(Text, Int)"));
register_function(_$breathe$main, Text("breathe.tm"), 22, Text("func main(Int, Int, Int, Int)"));
}
int _$breathe$main$parse_and_run(int argc, char *argv[]) {
#line 1
tomo_init();
_$breathe$$initialize();

Text_t usage = Texts(Text("Usage: "), Text$from_str(argv[0]), Text(" [--help] [--inhale-time=N] [--hold-time=N] [--exhale-time=N] [--cycles=N]"));
OptionalInt_t _$inhale_time = I_small(4);
OptionalInt_t _$hold_time = I_small(4);
OptionalInt_t _$exhale_time = I_small(4);
OptionalInt_t _$cycles = I_small(4);
tomo_parse_args(argc, argv, usage, usage,
{"inhale-time", false, &Int$info, &_$inhale_time},
{"hold-time", false, &Int$info, &_$hold_time},
{"exhale-time", false, &Int$info, &_$exhale_time},
{"cycles", false, &Int$info, &_$cycles});
_$breathe$main(_$inhale_time, _$hold_time, _$exhale_time, _$cycles);
return 0;
}
