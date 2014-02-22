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

#include <private/media/AudioTrackShared.h>
#include "AudioTrack.h"

namespace android {

// DEPRECATED
AudioTrack::AudioTrack(
        int streamType,
        uint32_t sampleRate,
        int format,
        int channelMask,
        int frameCount,
        uint32_t flags,
        callback_t cbf,
        void* user,
        int notificationFrames,
        int sessionId)
    : mStatus(NO_INIT),
      mIsTimed(false),
      mPreviousPriority(ANDROID_PRIORITY_NORMAL), mPreviousSchedulingGroup(SP_DEFAULT)
{
    mStatus = set((audio_stream_type_t)streamType, sampleRate, (audio_format_t)format,
            (audio_channel_mask_t) channelMask,
            frameCount, (audio_output_flags_t)flags, cbf, user, notificationFrames,
            0 /*sharedBuffer*/, false /*threadCanCallJava*/, sessionId);
}

void AudioTrack::mute(bool e)
{
    if (e) setVolume(0);
}

status_t AudioTrack::initCheck() const
{
    return mStatus;
}

// -------------------------------------------------------------------------

uint32_t AudioTrack::latency() const
{
    return mLatency;
}

uint32_t AudioTrack::channelCount() const
{
    return mChannelCount;
}

uint32_t AudioTrack::getSampleRate()
{
    if (mIsTimed) {
        return 0;
    }

    AutoMutex lock(mLock);
    return mSampleRate;
}

}; // namespace android
