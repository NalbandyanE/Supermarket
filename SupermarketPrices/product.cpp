#include "product.h"

Product::Product() = default;

Product::Product(const std::string& n, double p, const PricingScheme& pr) 
	: name{n}, price{p}, pricingScheme{pr} {}

Product::Product(const std::string& n, double p, int q, const PricingScheme& pr) 
	: name{n}, price{p}, quantity{q}, pricingScheme{pr} {}

Product::Product(const std::string& n, double p, double w, const PricingScheme& pr) 
	: name{n}, price{p}, weight{w}, pricingScheme{pr} {}

Product::Product(const std::string& n, double p, int q, double w, const PricingScheme& pr) 
	: name{n}, price{p}, quantity{q}, weight{w}, pricingScheme{pr} {}

void Product::setName(const std::string& n) {
	name = n;
}

void Product::setPrice(double p) {
	price = p;
}

std::string Product::getName() const {
	return name;
}

double Product::getPrice() const {
	return price;
}

void Product::setQuantity(int q) {
	quantity = q;
}

int Product::getQuantity() const {
	return quantity;
}

void Product::setWeight(double w) {
	weight = w;
}

double Product::getWeight() const {
	return weight;
}

void Product::setPricingScheme(const PricingScheme& pr) {
	pricingScheme = pr;
}

PricingScheme Product::getPricingScheme() const {
	return pricingScheme;
}