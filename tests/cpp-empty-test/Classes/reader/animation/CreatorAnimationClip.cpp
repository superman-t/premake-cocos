/****************************************************************************
 Copyright (c) 2017 Chukong Technologies Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "CreatorAnimationClip.h"

USING_NS_CCR;

CreatorAnimationClip* CreatorAnimationClip::create()
{
    auto animClip = new (std::nothrow) CreatorAnimationClip;
    if (animClip && animClip->init()) {
        animClip->autorelease();
        return animClip;
    }
    return nullptr;
}

bool CreatorAnimationClip::init()
{
    return true;
}

CreatorAnimationClip::CreatorAnimationClip()
: _name("")
, _speed(0)
, _sample(0)
, _duration(0)
, _wrapMode(WrapMode::Default)
{
}

CreatorAnimationClip::~CreatorAnimationClip()
{
}

void CreatorAnimationClip::setName(const std::string& name)
{
    _name = name;
}

const std::string& CreatorAnimationClip::getName() const
{
    return _name;
}

void CreatorAnimationClip::setDuration(float duration)
{
    _duration = duration;
}

float CreatorAnimationClip::getDuration() const
{
    return _duration;
}

void CreatorAnimationClip::setSample(float sample)
{
    _sample = sample;
}

float CreatorAnimationClip::getSample() const
{
    return _sample;
}

void CreatorAnimationClip::setSpeed(float speed)
{
    _speed = speed;
}

float CreatorAnimationClip::getSpeed() const
{
    return _speed;
}

void CreatorAnimationClip::setWrapMode(WrapMode wrapMode)
{
    _wrapMode = wrapMode;
}

creator::CreatorAnimationClip::WrapMode CreatorAnimationClip::getWrapMode() const
{
    return _wrapMode;
}

void CreatorAnimationClip::addAnimProperties(const AnimProperties& properties)
{
    _animPropertiesVec.push_back(properties);
}

const std::vector<AnimProperties>& CreatorAnimationClip::getAnimProperties() const
{
    return _animPropertiesVec;
}
