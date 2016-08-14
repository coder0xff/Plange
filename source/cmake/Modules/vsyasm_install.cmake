#This file will download and install vsyasm (http://www.tortall.net/projects/yasm/manual/html/vsyasm.html)
#into supported "SUPPORTED_VS_VERSIONS" installations of Visual Studio

function(vsyasm_install)
	if(${MSVC})
		set(DOWNLOADS_DIR "$ENV{USERPROFILE}\\Downloads")
		set(SUPPORTED_VS_VERSIONS "10" "11" "12" "14")

		set(USER_LEVEL 0 CACHE INTERNAL "")
		function(do_admin_check REASON)
			macro(denied)
				set(USER_LEVEL "USER" CACHE INTERNAL "")
				message(WARNING "Was not able to ${REASON}. Please run as administrator.")
				return()
			endmacro(denied)
			
			macro(granted)
				set(USER_LEVEL "ROOT" CACHE INTERNAL "")
				#message(STATUS "checked for elevated privileges before trying to ${REASON}")
				return()
			endmacro(granted)
			
			set(${RESULT_NAME} "TRUE" PARENT_SCOPE)
			if (USER_LEVEL STREQUAL "ROOT")
				granted()
			elseif (USER_LEVEL STREQUAL "USER")
				denied()
			endif()
			execute_process(COMMAND "cmd.exe" "/C dir $ENV{windir}\\temp" RESULT_VARIABLE TEST_RESULT OUTPUT_QUIET ERROR_QUIET)			
			if (NOT "${TEST_RESULT}" STREQUAL "0")
				denied ()
			else ()
				granted()
			endif()
		endfunction(do_admin_check)

		set(PROGS_PATH $ENV{ProgramFiles})
		set(X86_PROGS_PATH ${PROGS_PATH})
		set(X86_ENV_VAR "ProgramFiles(x86)")
		if (NOT "$ENV{${X86_ENV_VAR}}" STREQUAL "")
			set(X86_PROGS_PATH "$ENV{${X86_ENV_VAR}}")
		endif ()


		function(ver_to_path VERSION RESULT_VARIABLE)
			set(${RESULT_VARIABLE} "${X86_PROGS_PATH}\\Microsoft Visual Studio ${VERSION}.0" PARENT_SCOPE)
		endfunction(ver_to_path)
		
		function(ver_to_vc_bin_path VERSION RESULT_VARIABLE)
			ver_to_path(${VERSION} "TEMP")
			set(${RESULT_VARIABLE} "${TEMP}\\VC\\bin" PARENT_SCOPE)
		endfunction(ver_to_vc_bin_path)
		
		function(ver_to_vsyasm_path VERSION RESULT_VARIABLE)
			ver_to_vc_bin_path(${VERSION} "TEMP")
			set(${RESULT_VARIABLE} "${TEMP}\\vsyasm.exe" PARENT_SCOPE)
		endfunction(ver_to_vsyasm_path)
		

		set(INSTALLED_VS_VERSIONS "")
		foreach (V ${SUPPORTED_VS_VERSIONS})
			ver_to_vc_bin_path(${V} "VC_BIN_PATH")
			if(IS_DIRECTORY "${VC_BIN_PATH}")
				set(INSTALLED_VS_VERSIONS "${INSTALLED_VS_VERSIONS}" "${V}")
			endif(IS_DIRECTORY "${VC_BIN_PATH}")
		endforeach(V)

		if(NOT "${INSTALLED_VS_VERSIONS}" STREQUAL "")
			string(SUBSTRING "${INSTALLED_VS_VERSIONS}" 1 -1 INSTALLED_VS_VERSIONS)
			message(STATUS "Found Visual Studio versions: ${INSTALLED_VS_VERSIONS}")
			set(VSYASM_NOT_INSTALLED_VERSIONS "")
			foreach(V ${INSTALLED_VS_VERSIONS})
				ver_to_vsyasm_path(${V} "VSYASM_PATH")
				if(NOT EXISTS ${VSYASM_PATH})
					set(VSYASM_NOT_INSTALLED_VERSIONS "${VSYASM_NOT_INSTALLED_VERSIONS}" "${V}")
				endif(NOT EXISTS ${VSYASM_PATH})
			endforeach(V ${INSTALLED_VS_VERSIONS})		

			if (NOT "${VSYASM_NOT_INSTALLED_VERSIONS}" STREQUAL "")
				string(SUBSTRING "${VSYASM_NOT_INSTALLED_VERSIONS}" 1 -1 VSYASM_NOT_INSTALLED_VERSIONS)
				message("Installing vsyasm.exe for these Visual Studio versions: ${VSYASM_NOT_INSTALLED_VERSIONS}")				
				do_admin_check("install vsyasm")
				if ("${USER_LEVEL}" STREQUAL ROOT)
					set (VSYASM_VERSION 1.3.0)
					set (VSYASM_DL_FILENAME "vsyasm-${VSYASM_VERSION}-win64")
					if ("$ENV{${X86_ENV_VAR}}")
						set(VSYASM_DL_FILENAME "vsyasm-${VSYASM_VERSION}-win32")
					endif()
					set (VSYASM_DL_URI "http://www.tortall.net/projects/yasm/releases/${VSYASM_DL_FILENAME}.zip")
					file(MAKE_DIRECTORY "${DOWNLOADS_DIR}")
					set(VSYASM_DL_LOCATION "${DOWNLOADS_DIR}\\${VSYASM_DL_FILENAME}.zip")					
					if (NOT EXISTS "${VSYASM_DL_LOCATION}")
						message(STATUS "Downloading ${VSYASM_DL_URI} to ${VSYASM_DL_LOCATION}")
						file(DOWNLOAD "${VSYASM_DL_URI}" "${VSYASM_DL_LOCATION}")
					endif()
					file(MAKE_DIRECTORY "${DOWNLOADS_DIR}\\${VSYASM_DL_FILENAME}")
					execute_process(COMMAND "${CMAKE_COMMAND}" "-E" tar xf "${VSYASM_DL_LOCATION}" WORKING_DIRECTORY "${DOWNLOADS_DIR}\\${VSYASM_DL_FILENAME}")
					foreach (V ${VSYASM_NOT_INSTALLED_VERSIONS})
						ver_to_vc_bin_path(${V} VC_BIN_PATH)
						file(COPY "${DOWNLOADS_DIR}\\${VSYASM_DL_FILENAME}\\vsyasm.exe" DESTINATION "${VC_BIN_PATH}")
						message("Installed ${VC_BIN_PATH}\\vsyasm.exe")
					endforeach ()
				endif()
			endif()			
		endif()
	endif(${MSVC})
endfunction()

vsyasm_install()