%VULKAN_SDK%/Bin/glslangValidator.exe -V %~dp0\shader_base.vert
move %~dp0\vert.spv %~dp0\compiled/shader_base_vert.spv
%VULKAN_SDK%/Bin/glslangValidator.exe -V %~dp0\shader_base.frag
move %~dp0\frag.spv %~dp0\compiled/shader_base_frag.spv
