#include <iostream>
#include <vector>

//portefeuille est le module principal


int main() {
    Portefeuille mon_pf;

    mon_pf.enregistrer(TypeTransaction::Achat, 4000);
    mon_pf.enregistrer(TypeTransaction::Achat, 2000);
    mon_pf.enregistrer(TypeTransaction::Vente, 7500);

    std::cout << "Gain total : " << mon_pf.gain_total() << " argent\n";

    std::vector<double> rendements = { 0.04, -0.01, 0.05, 0.03, 0.00 };
    std::cout << "Rendement moyen : " << rendement_moyen(rendements) * 100 << " %\n";
    std::cout << "Volatilite : " << volatilite(rendements) * 100 << " %\n";

    return 0;
}
