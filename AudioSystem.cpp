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

#include "AudioSystem.h"

// ----------------------------------------------------------------------------

namespace android {

// DEPRECATED
status_t AudioSystem::getOutputSamplingRate(int* samplingRate, int streamType) {
    return getOutputSamplingRate(samplingRate, (audio_stream_type_t)streamType);
}

// DEPRECATED
status_t AudioSystem::getOutputFrameCount(int* frameCount, int streamType) {
    return getOutputFrameCount(frameCount, (audio_stream_type_t)streamType);
}

// DEPRECATED
status_t AudioSystem::getOutputLatency(uint32_t* latency, int streamType) {
    return getOutputLatency(latency, (audio_stream_type_t)streamType);
}

}; // namespace android

