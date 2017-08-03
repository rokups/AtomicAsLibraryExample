//
// Copyright (c) 2017 Rokas Kupstys
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#include <functional>

#include <Atomic/Engine/Application.h>
#include <Atomic/Core/CoreEvents.h>
#include <Atomic/Scene/Scene.h>
#include <Atomic/Graphics/Graphics.h>
#include <Atomic/Graphics/Renderer.h>
#include <Atomic/Graphics/Octree.h>
#include <Atomic/Graphics/Camera.h>
#include <Atomic/Graphics/Model.h>
#include <Atomic/Graphics/StaticModel.h>
#include <Atomic/Graphics/DebugRenderer.h>
#include <Atomic/Graphics/Technique.h>
#include <Atomic/Graphics/Texture2D.h>
#include <Atomic/IO/FileSystem.h>
#include <Atomic/IO/FileWatcher.h>
#include <Atomic/Resource/ResourceMapRouter.h>
#include <Atomic/Input/Input.h>
#include <Atomic/Graphics/CustomGeometry.h>
#include <Atomic/UI/SystemUI/SystemUI.h>
#include <Atomic/Core/StringUtils.h>
#include <Atomic/Engine/EngineDefs.h>


using namespace Atomic;
using namespace std::placeholders;

class AtomicAsLibraryExample : public Application
{
ATOMIC_OBJECT(AtomicAsLibraryExample, Application)
public:
    AtomicAsLibraryExample(Context* context) : Application(context) { }

    virtual void Setup()
    {
        // Modify engine startup parameters
        engineParameters_[EP_WINDOW_TITLE]   = GetTypeName();
        engineParameters_[EP_WINDOW_WIDTH]   = 1027;
        engineParameters_[EP_WINDOW_HEIGHT]  = 768;
        engineParameters_[EP_FULL_SCREEN]    = false;
        engineParameters_[EP_RESOURCE_PATHS] = "CoreData";

        // This is a dirty hack to make example run out of the box. You likely want to fix this.
        engineParameters_[EP_RESOURCE_PREFIX_PATHS] = CMAKE_SOURCE_DIR "/AtomicGameEngine/Resources";
    }

    virtual void Start()
    {
        context_->GetInput()->SetMouseVisible(true);
        SubscribeToEvent(E_SYSTEMUIFRAME, std::bind(&AtomicAsLibraryExample::OnUpdate, this, _2));
    }

    virtual void Stop()
    {
    }

    void OnUpdate(VariantMap& args)
    {
        if (ImGui::Begin("Example"))
        {
            ImGui::Text("This example application is using AtomicGameEngine as CMake dependency consumed through add_subdirectory().");
        }
        ImGui::End();
    }
};

ATOMIC_DEFINE_APPLICATION_MAIN(AtomicAsLibraryExample);
