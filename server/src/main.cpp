/*
** EPITECH PROJECT, 2020
** server
** File description:
** main
*/

#include "Config.hpp"
#include "Exception.hpp"
#include "GameServer.hpp"
#include "Server.hpp"

#include <fstream>
#include <iostream>

#define DEFAULT_CONFIG_FILE "r-type_server.json"

using namespace rtype;

static server::Config ParseConfig(const std::string &filePath)
{
    std::ifstream configFile(filePath.data());
    server::Config conf;

    if (!configFile.good())
        throw server::Exception("can't open config file: " + filePath);
    nlohmann::json::parse(configFile).get_to(conf);
    if (conf.maxGameThreads <= 0)
        conf.maxGameThreads = std::thread::hardware_concurrency();
    if (conf.maxGameThreads == 0)
        throw server::Exception("can't auto determine how many threads to use");
    conf.maxGameThreads -= conf.maxGameThreads != 0;
    return conf;
}

int main(int argc, const char **argv)
{
    boost::asio::io_context io_context;
    rtype::Network::IOServer<rtype::Network::UdpServer> server(io_context, 4219);

    server.start();
    //throw rtype::server::Network::IOException(e.msg())

    //const char *configFilePath = argc > 1 ? argv[1] : DEFAULT_CONFIG_FILE;

    //try {
        //server::Config conf = ParseConfig(configFilePath);
        //server::GameServer::Run(conf);
    //} catch (const std::exception &e) {
        //std::cerr << e.what() << std::endl;
        //return 1;
    //}
    return 0;
}
