#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include "price_calculator.h"
#include <vector>

class Supermarket {
public:
	Supermarket();
	Supermarket(const std::vector<Product>& p);
	std::vector<Product> getProducts() const;
	void setProducts(const std::vector<Product>& p);
	void addProduct(const Product& p);
	void deleteProduct(const Product& p);
	void updateProductName(Product& p, const std::string& n);
	void updateProductPrice(Product& p, double pr);
	void displayProducts() const;
	void displayInFile() const;
private:
	std::vector<Product> products;
};

#endif