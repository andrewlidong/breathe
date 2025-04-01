

# Display a progress bar during a breathing phase
func sleep_with_bar(phase: Text, duration: Int):
    symbol := "•"
    
    if phase == "Inhale":
        symbol = "↑"
    if phase == "Hold":
        symbol = "→"
    if phase == "Exhale":
        symbol = "↓"
    
    say("")
    say("  " ++ phase ++ " (" ++ Text(duration) ++ "s)")
    say("  ",)
    for i in duration:
        say(symbol,)
        sleep(1)
    say("")

func get_int(prompt: Text, default=4 -> Int):
    repeat:
        str := ask(prompt) or exit("Goodbye")
        if str == "":
            return default

        n := Int.parse(str)
        if n: return n

        say("Please give a valid integer")

    fail("unreachable")


func main(inhale_time=none:Int, hold_time=none:Int, exhale_time=none:Int, cycles=none:Int):
    say("
        ====================================
            Welcome to 🧘 BREATHE 🧘
        ====================================
    ")

    phases := &{:Text,Int}
    phases["inhale"] = inhale_time or get_int("How long would you like to inhale for? $\n")
    phases["hold"] = hold_time or get_int("How long would you like to hold your breath for? $\n")
    phases["exhale"] = exhale_time or get_int("How long would you like to exhale for? $\n")
    cycles = cycles or get_int("How many cycles would you like to do this for? $\n")

    say("  Inhale: " ++ Text(phases["inhale"]!) ++ "s | Hold: " ++ Text(phases["hold"]!) ++ "s")
    say("  Exhale: " ++ Text(phases["exhale"]!) ++ "s | Cycles: " ++ Text(cycles!))
    say("====================================")

    for i in cycles!:
        say("")
        say("------------------------------------")
        say("  CYCLE " ++ Text(i) ++ " of " ++ Text(cycles!))
        say("------------------------------------")
        
        sleep_with_bar("Inhale", phases["inhale"]!)
        sleep_with_bar("Hold", phases["hold"]!)
        sleep_with_bar("Exhale", phases["exhale"]!)
        sleep_with_bar("Hold", phases["hold"]!)

    say("")
    say("====================================")
    say("  ✅ BREATHE EASY ")
    say("====================================")
