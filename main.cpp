#include <iostream>
#include <string>
#include <map>

class FahrzeugKonfiguration {
private:
    std::string modell;
    std::string farbe;
    std::string motor;
    std::string felgen;
    std::string innenausstattung;

    // Preise für die Features
    double basisPreis;
    std::map<std::string, double> motorPreise;
    std::map<std::string, double> felgenPreise;
    std::map<std::string, double> innenausstattungPreise;

public:
    // Konstruktor
    FahrzeugKonfiguration(const std::string& m, double basisP)
        : modell(m), basisPreis(basisP) {
        // Standardpreise für die verschiedenen Features
        motorPreise = {
            {"V6 Benzin", 5000.0},
            {"V8 Benzin", 8000.0},
            {"V6 Diesel", 6000.0},
            {"Elektromotor", 10000.0}
        };

        felgenPreise = {
            {"18 Zoll Standard", 500.0},
            {"19 Zoll Sportfelgen", 1000.0},
            {"20 Zoll Chromfelgen", 1500.0}
        };

        innenausstattungPreise = {
            {"Stoff", 0.0},
            {"Leder, Schwarz", 2000.0},
            {"Leder, Beige", 2500.0}
        };
    }

    // Set-Methoden für die Features
    void setFarbe(const std::string& f) {
        farbe = f;
    }

    void setMotor(const std::string& mo) {
        if (motorPreise.find(mo) != motorPreise.end()) {
            motor = mo;
        } else {
            std::cout << "Ungültiger Motor gewählt!\n";
        }
    }

    void setFelgen(const std::string& fe) {
        if (felgenPreise.find(fe) != felgenPreise.end()) {
            felgen = fe;
        } else {
            std::cout << "Ungültige Felgen gewählt!\n";
        }
    }

    void setInnenausstattung(const std::string& ia) {
        if (innenausstattungPreise.find(ia) != innenausstattungPreise.end()) {
            innenausstattung = ia;
        } else {
            std::cout << "Ungültige Innenausstattung gewählt!\n";
        }
    }

    // Methode zur Berechnung des Gesamtpreises
    double berechneGesamtPreis() const {
        double gesamtPreis = basisPreis;

        // Preis der gewählten Features hinzufügen
        if (motorPreise.find(motor) != motorPreise.end()) {
            gesamtPreis += motorPreise.at(motor);
        }

        if (felgenPreise.find(felgen) != felgenPreise.end()) {
            gesamtPreis += felgenPreise.at(felgen);
        }

        if (innenausstattungPreise.find(innenausstattung) != innenausstattungPreise.end()) {
            gesamtPreis += innenausstattungPreise.at(innenausstattung);
        }

        return gesamtPreis;
    }

    // Methode zur Darstellung der Konfiguration
    void zeigeKonfiguration() const {
        std::cout << "Fahrzeugkonfiguration:\n"
                  << "Modell: " << modell << "\n"
                  << "Farbe: " << farbe << "\n"
                  << "Motor: " << motor << " (Preis: " << motorPreise.at(motor) << " Euro)\n"
                  << "Felgen: " << felgen << " (Preis: " << felgenPreise.at(felgen) << " Euro)\n"
                  << "Innenausstattung: " << innenausstattung << " (Preis: " << innenausstattungPreise.at(innenausstattung) << " Euro)\n"
                  << "Gesamtpreis: " << berechneGesamtPreis() << " Euro\n";
    }
};

int main() {
    // Erstellen einer Fahrzeugkonfiguration mit Basispreis
    FahrzeugKonfiguration config("Audi A6", 45000.0);

    // Features setzen
    config.setFarbe("Weiß");
    config.setMotor("V6 Benzin");
    config.setFelgen("20 Zoll Chromfelgen");
    config.setInnenausstattung("Leder, Schwarz");

    // Konfiguration anzeigen und Gesamtpreis berechnen
    config.zeigeKonfiguration();

    return 0;
}
