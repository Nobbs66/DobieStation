#ifndef GIF_HPP
#define GIF_HPP
#include <cstdint>

#include "int128.hpp"

class GraphicsSynthesizer;

struct GIFtag
{
    uint16_t NLOOP;
    bool end_of_packet;
    bool output_PRIM;
    uint16_t PRIM;
    uint8_t format;
    uint8_t reg_count;
    uint64_t regs;

    uint8_t regs_left;
    uint32_t data_left;
};

class GraphicsInterface
{
    private:
        GraphicsSynthesizer* gs;
        GIFtag current_tag;
        bool processing_GIF_prim;

        void process_PACKED(uint128_t quad);
        void process_REGLIST(uint128_t quad);
        void feed_GIF(uint128_t quad);
    public:
        GraphicsInterface(GraphicsSynthesizer* gs);
        void reset();
        void send_PATH2(uint32_t data[4]);
        void send_PATH3(uint128_t quad);
};

#endif // GIF_HPP
