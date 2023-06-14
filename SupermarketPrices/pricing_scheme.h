#ifndef PRICING_SCHEME_H
#define PRICING_SCHEME_H

class PricingScheme {
public:
	enum class PricingSchemeType {
		SIMPLE, THREE_FOR_DOLLAR, PRICE_PER_WEIGHT, BUY_TWO_GET_ONE_FREE
	};
	PricingScheme();
	PricingScheme(PricingSchemeType, double);
	PricingSchemeType getType() const;
	double getValue() const;
	void setType(PricingSchemeType);
	void setValue(double);
private:
	PricingSchemeType type;
	double value;
};

#endif