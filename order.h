#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "orderBookLevelInfo.h"
#include <cstdlib>
#include <stdexcept>
#include <format>

class Order {
private:
    OrderType ordertype_;
    OrderId orderId_;
    Side side_;
    Price price_;
    Quantity initialQuantity_;
    Quantity remainingQuantity_;
public:
    Order(OrderType ordertype, OrderId orderId, Side side, Price price, Quantity quantity)
        : ordertype_(ordertype)
        , orderId_(orderId)
        , side_(side)
        , price_(price)
        , initialQuantity_(quantity)
        , remainingQuantity_(quantity) 
    {}

    OrderId GetOrderId() const {
        return orderId_;
    }

    Side GetSide() const {
        return side_;
    }

    Price GetPrice() const {
        return price_;
    }

    OrderType GetOrderType() const {
        return ordertype_;
    }

    Quantity GetInitialQuantity() const {
        return initialQuantity_;
    }

    Quantity GetRemainingQuantity() const {
        return remainingQuantity_;
    }
    
    Quantity GetFilledQuantity() const {
        return GetInitialQuantity() - GetRemainingQuantity();
    }

    void Fill(Quantity quantity) {
        if (quantity > GetRemainingQuantity()) {
            throw std::logic_error(std::format("Order ({}) cannot be filled for more than its remaining quantity.", GetOrderId()));

            remainingQuantity_ -= quantity;
        }
    }
};

#endif
