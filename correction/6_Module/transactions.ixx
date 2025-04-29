export module portefeuille:transactions;

#include <vector>

export enum class TypeTransaction {
    Achat,
    Vente
};

export struct Transaction {
    TypeTransaction type;
    double montant;
};

export class Portefeuille {
private:
    std::vector<Transaction> transactions;

public:
    void enregistrer(TypeTransaction type, double montant) {
        transactions.push_back({type, montant});
    }
	//calcule le montant total des transactions d'un type donne
    double montant_total(TypeTransaction type) const {
        double total = 0.0;
        for (const auto& t : transactions) {
            if (t.type == type) {
                total += t.montant;
            }
        }
        return total;
    }

	//calcule le gain total entre les achats et les ventes
    double gain_total() const {
        double achats = montant_total(TypeTransaction::Achat);
        double ventes = montant_total(TypeTransaction::Vente);
        return ventes-achats;
    }
};
