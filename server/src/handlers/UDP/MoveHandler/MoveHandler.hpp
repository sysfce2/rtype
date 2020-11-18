/*
** EPITECH PROJECT, 2020
** B-CPP-501-BDX-5-1-rtype-albert.corson
** File description:
** MoveHandler
*/

#pragma once

#include "Player.hpp"
#include "handlers/AHandlerUDP.hpp"
#include "types.hpp"

#include <sys/types.h>
#include <vector>

namespace rtype::server {
    class MoveHandler : public AHandlerUDP {
      public:
        struct ClientRequestBody {
            entity_id_t playerID;
            Direction direction;
            bool state;
        };

        MoveHandler(Lobby &owner);
        ~MoveHandler() override = default;

      protected:
        void receiveResponse(const Network::UdpPackage &package) override;
        void receiveRequest(const Network::UdpPackage &package) override;
        BPC::Method getMethod() const override;
    };
}
