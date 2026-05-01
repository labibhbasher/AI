import random

risk_levels = [0.10, 0.25, 0.40, 0.55, 0.70, 0.85]

simulations = 100   
rounds = 10         

print("Risk Level\tChoose Stag %\tChoose Hare %\tAverage Points")
print("-" * 65)

for risk in risk_levels:
    total_stag = 0
    total_hare = 0
    total_points_all = 0

    for sim in range(simulations):
        choose_stag = 0
        choose_hare = 0
        total_points = 0

        for r in range(rounds):
            hunter_a = "Stag" if random.random() > risk else "Hare"
            hunter_b = "Stag" if random.random() > risk else "Hare"

            # Count choices
            if hunter_a == "Stag":
                choose_stag += 1
            else:
                choose_hare += 1

            if hunter_b == "Stag":
                choose_stag += 1
            else:
                choose_hare += 1

            # Payoff
            if hunter_a == "Stag" and hunter_b == "Stag":
                total_points += 20
            elif hunter_a == "Hare" and hunter_b == "Hare":
                total_points += 14
            else:
                total_points += 7

        total_stag += choose_stag
        total_hare += choose_hare
        total_points_all += total_points

    total_choices = total_stag + total_hare
    stag_percent = (total_stag / total_choices) * 100
    hare_percent = (total_hare / total_choices) * 100
    average_points = total_points_all / (simulations * rounds)

    print(f"{int(risk*100)}%\t\t{stag_percent:.1f}%\t\t{hare_percent:.1f}%\t\t{average_points:.2f}")