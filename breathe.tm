
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

func main(inhale_time=4, hold_time=4, exhale_time=4, cycles=4):
    say("====================================")
    say("  🧘 BREATHE 🧘")
    say("====================================")
    say("  Inhale: " ++ Text(inhale_time) ++ "s | Hold: " ++ Text(hold_time) ++ "s")
    say("  Exhale: " ++ Text(exhale_time) ++ "s | Cycles: " ++ Text(cycles))
    say("====================================")

    for i in cycles:
        say("")
        say("------------------------------------")
        say("  CYCLE " ++ Text(i) ++ " of " ++ Text(cycles))
        say("------------------------------------")
        sleep_with_bar("Inhale", inhale_time)
        sleep_with_bar("Hold", hold_time)
        sleep_with_bar("Exhale", exhale_time)
        sleep_with_bar("Hold", hold_time)

    say("")
    say("====================================")
    say("  ✅ BREATHE EASY ")
    say("====================================")