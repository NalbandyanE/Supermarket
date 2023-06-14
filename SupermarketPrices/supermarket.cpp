#include "supermarket.h"
#include "price_calculator.h"
#include <iostream>
#include <fstream>

Supermarket::Supermarket() = default;

Supermarket::Supermarket(const std::vector<Product>& p) : products{p} {}

std::vector<Product> Supermarket::getProducts() const {
	return products;
}

void Supermarket::setProducts(const std::vector<Product>& p) {
	products = p;
}

void Supermarket::addProduct(const Product& p) {
	products.push_back(p);
}

void Supermarket::deleteProduct(const Product& p) {
	bool found = false;
	for (int i = 0; i < products.size(); ++i) {
		if (products[i].getName() == p.getName()) {
			products.erase(products.begin() + i);
			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "Product doesn't exist." << std::endl;
	}
}

void Supermarket::updateProductName(Product& p, const std::string& n) {
    	for (Product& product : products) {
        	if (product.getName() == p.getName()) {
            		product.setName(n);
            		return;
        	}
    	}
    	std::cout << "Product not found." << std::endl;
}

void Supermarket::updateProductPrice(Product& p, double pr) {
    	for (Product& product : products) {
        	if (product.getName() == p.getName()) {
            		product.setPrice(pr);
            		return;
        	}
    	}
    	std::cout << "Product not found." << std::endl;
}


void Supermarket::displayProducts() const {
	std::cout << "Displaying products in supermarket:" << std::endl;
	std::cout << "Number\tName\tPrice\tQuantity Weight\tCalculatedPriceForAllQuantityOrWeight" <<std::endl;
	for (int i = 0; i < products.size(); ++i) {
		std::cout << i + 1 << "\t" << products[i].getName() << "\t" << products[i].getPrice() << "dram\t";
		if (products[i].getPricingScheme().getType() == PricingScheme::PricingSchemeType::SIMPLE || 
			products[i].getPricingScheme().getType() == PricingScheme::PricingSchemeType::THREE_FOR_DOLLAR ||
			products[i].getPricingScheme().getType() == PricingScheme::PricingSchemeType::BUY_TWO_GET_ONE_FREE) {
			std::cout << products[i].getQuantity() << "\t-\t";
		} 
		else if (products[i].getPricingScheme().getType() == PricingScheme::PricingSchemeType::PRICE_PER_WEIGHT){
			std::cout << "-\t" << products[i].getWeight() << "\t";
		}
		std::cout << "\t" << PriceCalculator::calculate(products[i]) << "dram" << std::endl;
	}
}

void Supermarket::displayInFile() const {
	std::ofstream file("products.txt");
	file << "Displaying products in supermarket:" << std::endl;
	file << "Number\tName\tPrice\tQuantity Weight\tCalculatedPriceForAllQuantityOrWeight" <<std::endl;
	for (int i = 0; i < products.size(); ++i) {
		file << i + 1 << "\t" << products[i].getName() << "\t" << products[i].getPrice() << "dram\t";
		if (products[i].getPricingScheme().getType() == PricingScheme::PricingSchemeType::SIMPLE || 
			products[i].getPricingScheme().getType() == PricingScheme::PricingSchemeType::THREE_FOR_DOLLAR ||
			products[i].getPricingScheme().getType() == PricingScheme::PricingSchemeType::BUY_TWO_GET_ONE_FREE) {
			file << products[i].getQuantity() << "\t-\t";
		} 
		else if (products[i].getPricingScheme().getType() == PricingScheme::PricingSchemeType::PRICE_PER_WEIGHT){
			file << "-\t" << products[i].getWeight() << "\t";
		}
		file << "\t" << PriceCalculator::calculate(products[i]) << "dram" << std::endl;
	}
	file.close();
}
