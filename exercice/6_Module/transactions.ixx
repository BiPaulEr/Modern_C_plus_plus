//module portefeuille - transactions

#include <vector>

enum class TypeTransaction {
    Achat,
    Vente
};

struct Transaction {
    TypeTransaction type;
    double montant;
};

class Portefeuille {
private:
    std::vector<Transaction> transactions;

public:
    void enregistrer(TypeTransaction type, double montant) {
        transactions.push_back({type, montant});
    }
	//calcule le montant total des transactions d'un type donne
    double montant_total(TypeTransaction type) const {
        double total = 0.0;
        return total;
    }

	//calcule le gain total entre les achats et les ventes
    double gain_total() const {
        return 0.0;
    }
};
