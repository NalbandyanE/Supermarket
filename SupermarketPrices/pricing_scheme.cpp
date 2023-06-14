#include "pricing_scheme.h"

PricingScheme::PricingScheme() = default;

PricingScheme::PricingScheme(PricingSchemeType d, double v) : type{d}, value{v} {}

PricingScheme::PricingSchemeType PricingScheme::getType() const {
	return type;
}

double PricingScheme::getValue() const {
	return value;
}

void PricingScheme::setType(PricingSchemeType d) {
	type = d;
}

void PricingScheme::setValue(double v) {
	value = v;
}