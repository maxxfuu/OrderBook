#ifndef ORDERMODIFY_H
#define ORDERMODIFY_H

#include <list>
#include "orderbook.h"
#include "OrderBookLevelInfo.h"

using OrderPointer = std::shared_ptr<Order>;
using OrderPointers = std::list<OrderPointer>;

class OrderModify {
private:
    OrderId orderId_;
    Side side_;
    Price price_;
    Quantity quantity_;

public:
    OrderModify(OrderId orderId, Side side, Price price, Quantity quantity) 
        : orderId_(orderId)
        , side_(side)
        , price_(price)
        , quantity_(quantity)
    {}

    OrderId GetOrderId() const {
        return orderId_;
    }

    Price GetPrice() const {
        return price_;
    }

    Side GetSide() const {
        return side_;
    }

    Quantity GetQuantity() const {
        return quantity_;
    }
    
    // Convert a pre-existing given order into a new modified order
    OrderPointer ToOrderPointer(OrderType type) const {
        return std::make_shared<Order>(type, GetOrderId(), GetSide(), GetPrice(), GetQuantity());
     }


};

#endif
