import random

SILENT = "Silent"
CONFESS = "Confess"

def payoff(a, b):
    if a == SILENT and b == SILENT:
        return (1, 1)
    elif a == SILENT and b == CONFESS:
        return (20, 0)
    elif a == CONFESS and b == SILENT:
        return (0, 20)
    else:
        return (5, 5)

def random_choice():
    return random.choice([SILENT, CONFESS])

def cooperative_choice():
    return random.choices([SILENT, CONFESS], weights=[0.7, 0.3])[0]

pairs = 100
rounds = 10

no_comm_total = [0, 0]
comm_total = [0, 0]

# count cooperation
no_comm_coop = 0
comm_coop = 0

for _ in range(pairs):
    for r in range(rounds):
        
        if r < 5:
            a = random_choice()
            b = random_choice()
            p1, p2 = payoff(a, b)
            no_comm_total[0] += p1
            no_comm_total[1] += p2

            if a == SILENT and b == SILENT:
                no_comm_coop += 1

        else:
            a = cooperative_choice()
            b = cooperative_choice()
            p1, p2 = payoff(a, b)
            comm_total[0] += p1
            comm_total[1] += p2

            if a == SILENT and b == SILENT:
                comm_coop += 1

# total rounds per phase
total_rounds = pairs * 5

# rates
no_comm_rate = (no_comm_coop / total_rounds) * 100
comm_rate = (comm_coop / total_rounds) * 100

no_comm_defect = 100 - no_comm_rate
comm_defect = 100 - comm_rate

improvement = comm_rate - no_comm_rate

# ✅ PRINT TABLE
print("\nResults:\n")

print("--------------------------------------------------------")
print("| {:<20} | {:<22} | {:<18} |".format(
    "", "Without Communication", "With Communication"))
print("--------------------------------------------------------")

print("| {:<20} | {:<22.1f}% | {:<18.1f}% |".format(
    "Cooperation Rate", no_comm_rate, comm_rate))

print("| {:<20} | {:<22.1f}% | {:<18.1f}% |".format(
    "Defection Rate", no_comm_defect, comm_defect))

print("| {:<20} | {:<22} | {:<18.1f}% |".format(
    "Improvement", "-", improvement))

print("--------------------------------------------------------")