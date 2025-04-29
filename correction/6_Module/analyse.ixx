export module portefeuille:analyse;
// subpartitions de portefeuille nomme analyse
#include <vector>
#include <numeric>
#include <cmath>

//calcule le rendement moyen
export double rendement_moyen(const std::vector<double>& rendements) {
    if (rendements.empty()) return 0.0;
    double somme = std::accumulate(rendements.begin(), rendements.end(), 0.0);
    return somme / rendements.size();
}

//calcule la variance
export double volatilite(const std::vector<double>& rendements) {
    if (rendements.empty()) return 0.0;

    double moyenne = rendement_moyen(rendements);
    double somme_ecarts_carres = 0.0;

    for (double r : rendements) {
        somme_ecarts_carres += (r - moyenne) * (r - moyenne);
    }

    double variance = somme_ecarts_carres / rendements.size();
    return std::sqrt(variance);
}
