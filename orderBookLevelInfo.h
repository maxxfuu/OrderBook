#ifndef ORDERBOOKLEVELSINFO_H
#define ORDERBOOKLEVELSINFO_H

#include<cstdint>
#include<vector>

using Price = std::int32_t;
using Quantity = std::uint32_t;
using OrderId = std::uint64_t;

enum class OrderType {
    GoodTillCancel,
    FillAndKill
};

enum class Side {
    Buy,
    Sell
};

struct LevelInfo {
    Price price_;
    Quantity quantity_;
};

using LevelInfos = std::vector<LevelInfo>;

class OrderBookLevelInfos {
private:
    LevelInfos bids_;
    LevelInfos asks_;

public:
    OrderBookLevelInfos(const LevelInfos& bids, const LevelInfos& asks) : bids_(bids), asks_(asks) {}

    const LevelInfos& GetBids() const {
        return bids_;
    }

    const LevelInfos& GetAsks() const {
        return asks_;
    }
};

#endif
