/*
** EPITECH PROJECT, 2020
** B-CPP-501-BDX-5-1-rtype-albert.corson
** File description:
** JoinHandler
*/

#pragma once

#include "Player.hpp"
#include "handlers/AHandlerUDP.hpp"
#include "types.hpp"

#include <vector>

namespace rtype::server {
    class JoinHandler : public AHandlerUDP {
      public:
        struct ServerRequestBody {
            entity_id_t playerID;
            std::vector<unsigned char> mapName;
        };

        JoinHandler(Lobby &owner);
        ~JoinHandler() override = default;

      protected:
        void receiveResponse(const Network::UdpPackage &package) override;
        void receiveRequest(const Network::UdpPackage &package) override;
        BPC::Method getMethod() const override;
    };
}
