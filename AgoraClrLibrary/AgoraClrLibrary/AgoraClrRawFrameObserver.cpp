#include "stdafx.h"
#include "AgoraClrRawFrameObserver.h"

using namespace AgoraClrLibrary;

AgoraClrRawFrameObserver::AgoraClrRawFrameObserver()
{
	m_VIDEO_FRAME_TYPE = VIDEO_FRAME_TYPE::FRAME_TYPE_YUV420; //default
}

bool AgoraClrRawFrameObserver::onRecordAudioFrame(AudioFrame & audioFrame)
{
	if (onRecordAudioFrameEvent) return onRecordAudioFrameEvent(audioFrame);
	else return true;
}

bool AgoraClrRawFrameObserver::onPlaybackAudioFrame(AudioFrame & audioFrame)
{
	if (onPlaybackAudioFrameEvent) return onPlaybackAudioFrameEvent(audioFrame);
	else return true;
}

bool AgoraClrLibrary::AgoraClrRawFrameObserver::onMixedAudioFrame(AudioFrame & audioFrame)
{
	if (onMixedAudioFrameEvent) return onMixedAudioFrameEvent(audioFrame);
	else return false;
}

bool AgoraClrRawFrameObserver::onPlaybackAudioFrameBeforeMixing(unsigned int uid, AudioFrame & audioFrame)
{
	if (onPlaybackAudioFrameBeforeMixingEvent) return onPlaybackAudioFrameBeforeMixingEvent(uid, audioFrame);
	else return true;
}

bool AgoraClrRawFrameObserver::onCaptureVideoFrame(VideoFrame & videoFrame)
{
	if (onCaptureVideoFrameEvent) return onCaptureVideoFrameEvent(videoFrame);
	else return true;
}

bool AgoraClrRawFrameObserver::onRenderVideoFrame(unsigned int uid, VideoFrame & videoFrame)
{
	if (onRenderVideoFrameEvent) return onRenderVideoFrameEvent(uid, videoFrame);
	else return true;
}

IVideoFrameObserver::VIDEO_FRAME_TYPE AgoraClrRawFrameObserver::getVideoFormatPreference()
{
	return m_VIDEO_FRAME_TYPE;
}

void AgoraClrRawFrameObserver::setVideoFormatPreference(VIDEO_FRAME_TYPE videoFrame)
{
	m_VIDEO_FRAME_TYPE = videoFrame;
}
