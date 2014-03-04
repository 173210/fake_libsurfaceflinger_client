/*
 * Copyright (C) 2014 173210 <root.3.173210@live.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <binder/Parcel.h>
#include "Surface.h"

namespace android {

status_t Surface::writeToParcel(
        const sp<Surface>& surface, Parcel* parcel) {
    sp<IGraphicBufferProducer> bp;
    if (surface != NULL) {
        bp = surface->getIGraphicBufferProducer();
    }
    return parcel->writeStrongBinder(bp->asBinder());
}

sp<Surface> Surface::readFromParcel(const Parcel& data) {
    sp<IBinder> binder(data.readStrongBinder());
    sp<IGraphicBufferProducer> bp(interface_cast<IGraphicBufferProducer>(binder));
    return bp != NULL ? new Surface(bp): NULL;
}

}; // namespace android

