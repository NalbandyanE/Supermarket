#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include "pricing_scheme.h"

class Product {
public:
	Product();
	Product(const std::string&, double, const PricingScheme&);
	Product(const std::string&, double, int, const PricingScheme&);
	Product(const std::string&, double, double, const PricingScheme&);
	Product(const std::string&, double, int, double, const PricingScheme&);
	void setName(const std::string&);
	void setPrice(double);
	std::string getName() const;
	double getPrice() const;
	void setQuantity(int);
	int getQuantity() const;
	void setWeight(double);
	double getWeight() const;
	void setPricingScheme(const PricingScheme&);
	PricingScheme getPricingScheme() const;
private:
	std::string name;
	double price;
	int quantity;
	double weight;
	PricingScheme pricingScheme;
};

#endif