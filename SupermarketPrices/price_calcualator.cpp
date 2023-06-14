#include "price_calculator.h"
#include <iostream>

double PriceCalculator::calculate(const Product& p) {
	switch (p.getPricingScheme().getType()) {
		case PricingScheme::PricingSchemeType::SIMPLE:
			return calculateSimplePrice(p);
		case PricingScheme::PricingSchemeType::THREE_FOR_DOLLAR:
			return calculateThreeForDollarPrice(p);
		case PricingScheme::PricingSchemeType::PRICE_PER_WEIGHT:
			return calculatePricePerWeight(p);
		case PricingScheme::PricingSchemeType::BUY_TWO_GET_ONE_FREE:
			return calculateBuyTwoGetOnePrice(p);
		default:
			std::cout << "There are no such type." << std::endl;
			return 0.0;
	}
}

double PriceCalculator::calculateSimplePrice(const Product& p) {
	return p.getPrice() * p.getQuantity();
}

double PriceCalculator::calculateThreeForDollarPrice(const Product& p) {
	int count = p.getQuantity() / 3;
	int remaining = p.getQuantity() % 3;
	double total = count * 386.0;
	total += remaining * 386.0 / 3.0;
	return total;
}

double PriceCalculator::calculatePricePerWeight(const Product& p) {
	double gram = p.getPrice() / 1000;
	return gram * p.getWeight();
}

double PriceCalculator::calculateBuyTwoGetOnePrice(const Product& p) {
	int count = p.getQuantity() / 3;
	int remaining = p.getQuantity() % 3;
	double total = count * 2.0 * p.getPrice();
	total += remaining * p.getPrice();
	return total;
}