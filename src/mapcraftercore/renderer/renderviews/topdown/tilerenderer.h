/*
 * Copyright 2012-2015 Moritz Hilscher
 *
 * This file is part of Mapcrafter.
 *
 * Mapcrafter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mapcrafter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Mapcrafter.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TOPDOWN_TILERENDERER_H_
#define TOPDOWN_TILERENDERER_H_

#include "blockimages.h"
#include "tileset.h"
#include "../../tilerenderer.h"
#include "../../image.h"
#include "../../../config/sections/map.h"
#include "../../../config/sections/world.h"
#include "../../../mc/worldcache.h"
#include "../../../util.h"

#include <memory>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace mapcrafter {
namespace renderer {

class TopdownTileRenderer : public TileRenderer {
public:
	TopdownTileRenderer(std::shared_ptr<BlockImages> images, int tile_width,
			std::shared_ptr<mc::WorldCache> world, RenderModes& render_modes);
	~TopdownTileRenderer();

	void renderChunk(const mc::Chunk& chunk, RGBAImage& tile, int dx, int dy);
	virtual void renderTile(const TilePos& tile_pos, RGBAImage& tile);

	virtual int getTileSize() const;
};

}
}

#endif /* TOPDOWN_TILERENDERER_H_ */