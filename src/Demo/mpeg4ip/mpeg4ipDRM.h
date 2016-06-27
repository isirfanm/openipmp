/** \mainpage mpeg4ip DRM support.

    Here we present mpeg4ip with support for protecting and playing protected content using DRM
    plugin architecture. For details about changes that were needed to add DRM support to mpeg4ip,
    see the sources provided (<a href="files.html">files</a>). Look for comments "BEGIN Added for DRM
    support" and "END Added for DRM support".<br>
    
    To build and use mpeg4ip with DRM support, unpack src/Demo/mpeg4ip/mpeg4ip-1.5.rar to some directory.<br>
    On Windows platform, use Microsoft Visual Studio 6 workspace DRMPluginAll.dsw (see DRM plugin
    documentation) to build the SDK. Copy the created DRMPlugin directory with headers and binaries
    to mpeg4ip-1.5 root directory.<br>
    On Linux platform, follow the instructions from DRM plugin documentation to build and install the SDK.<br>

    One can now follow the mpeg4ip instructions on how to build and install it.<br>

    Here is a brief overview for windows platform:
    <ul>
    <li>load mpeg4ip-1.5/encoding60.dsw in Visual Studio 6 and build mp4creator application.</li>
    <li>load mpeg4ip-1.5/player/srcplayer60.dsw in Visual Studio 6 and build mp4player application.</li>
    <li>either use mp4creator and mp4player from Visual Studio or copy them wherever you like together
    with all the dynamic link libraries from DRMPlugin directory.</li>
    </ul>
    A brief overview for linux platform:
    <ul>
    <li>go to mpeg4ip-1.5/SDL directory.</li>
    <li>run "chmod +x configure".</li>
    <li>run "./configure", "make" and "make install" (needs root privileges).</li>
    <li>go to mpeg4ip-1.5 directory.</li>
    <li>run "chmod +x cvs_bootstrap configure".</li>
    <li>run "./cvs_bootstrap --disable-mp4live", "make" and "make install" (needs root privileges).</li>
    <li>export necessary environment variables: "export LD_LIBRARY_PATH=/usr/local/lib:/usr/local/lib/mp4player_plugin:/usr/local/lib/DRMPlugin"</li>
    <li>use mp4creator and mp4player from shell.</li>
    </ul>

    DRMPlugin SDK supports both creating protected files and decoding protected files.
    For protecting files see <a href="#enc">mp4creator</a>
    and for playing protected files see <a href="#dec">mp4player</a>.<br><br>
    
    <div id="enc">
    <h2><b>mp4creator with DRM support</b></h2>
    </div>
    mp4creator application is used to encode content. Besides standard mpeg4ip parameters,
    it now takes certain parameters needed for DRM encryption.<br>
    -E option is used to set encryption of all (audio and video) tracks in a file,
    and -E=&lt;track ID&gt; is used to set encryption of a track corresponding to track ID
    (identifier).<br>
    
    Further, DRM options are the following:
    <ul>
    <li>-W=&lt;xml file name&gt;, [mandatory], set XML configuration file name.</li>
    <li>-X=&lt;sensitive data&gt;, set sensitive information.</li>
    <li>-Y=&lt;drm method&gt;;&lt;encryption method&gt;, [mandatory], set protection methods.</li>
    </ul>
    
    XML configuration file contains necessary information for DRM encryption.<br>
    
    Sensitive information is set via command line if it shouldn't appear in the
    XML configuration file (user name, password, licenses...). -X option can be used
    multiple times. &lt;sensitive data&gt; can be:
    <ul>
    <li>UserName;&lt;user name&gt;, [mandatory, only one], user name for DRM server access.</li>
    <li>UserPass;&lt;password&gt;, [mandatory, only one], user password for DRM server access.</li>
    <li>License;&lt;user name&gt;;&lt;start date&gt;;&lt;end date&gt;;&lt;license format&gt;,
      [mandatory for ISMA and openIPMP DRM, can be more than one], where
      start and end date must be formatted as &lt;YYYY&gt;-&lt;MM&gt;-&lt;DD&gt;,
      and license format must be ODRL. License will be added for user identified by user name and
      for given time period.</li>
    <li>License;&lt;device identifier&gt;;&lt;start date&gt;;&lt;end date&gt;,
      [mandatory for OMA DRM, can be more than one], where start and end date
      must be formatted as &lt;YYYY&gt;-&lt;MM&gt;-&lt;DD&gt;T&lt;HH&gt;:&lt;MM&gt;:&lt;SS&gt;Z,
      and one can use OMADRMDeviceIDCalc application (from DRMPlugin binaries) to calculate
      the device identifier from DER encoded X509 certificate file. License will be added for
      device identified by device identifier and for given time period.</li>
    </ul>
    
    DRM and encryption method must be one of the following combinations: oma;cbc,
    oma;ctr, isma;icm, openipmp;bfs, openipmp;ctr.<br>
    oma, isma and openipmp stand for OMA DRM, ISMA DRM and openIPMP DRM protection,
    respectively.<br>
    cbc, ctr and icm stand for AES encryption with 128-bit key, and cipher block chaining,
    counter and integer counter modes, respectively.<br>
    bfs stands for blowfish encryption.<br>
    
    Sample XML configuration file for encryption (windows paths must be changed to unix paths
    if encrypting on a linux platform): <a href="../EncoderInfo.xml">EncoderInfo</a> <br>
    
    RightsHostURL tag in XML configuration file must be set to IP address of a host
    where DRM server is installed and working.<br>
    P12FilePath tag in XML configuration file must be set to the path where .p12 file for the user identified
    with UserName and UserPass (see above) resides. See DRMPlugin documentation on how to create a user
    and get a .p12 user file.<br>
    RandomNumberFilePath tag in XML configuration file must be set to the path where entropy.dat will reside.
    Can be left as it is.<br>
    For testing purposes, other tags in XML configuration file can be left as they are.<br>

    For all the following sample command lines, it is assumed that test30.mp4 is a plain mp4 file which
    will be protected and saved as enc-test30.mp4.<br>
    
    Here is a sample command line for OMA encryption on windows platform:<br>
    <em>mp4creator -E -W=EncoderInfo.xml -X=UserName;danijelk -X=UserPass;ipmp -X=License;dG2IhDioBnMdX1faxsuX0MCCmaQ=;2006-01-02T00:00:00Z;2006-12-31T00:00:00Z -Y=oma;cbc test30.mp4 enc-test30.mp4</em>.<br><br>
    Here is a sample command line for OMA encryption on linux platform:<br>
    <em>mp4creator -E -W="EncoderInfo.xml" -X="UserName;danijelk" -X="UserPass;ipmp" -X="License;dG2IhDioBnMdX1faxsuX0MCCmaQ=;2006-01-02T00:00:00Z;2006-12-31T00:00:00Z" -Y="oma;cbc" test30.mp4 enc-test30.mp4</em>.<br>
    
    Here is a sample command line for ISMA encryption on windows platform:<br>
    <em>mp4creator -E -W=EncoderInfo.xml -X=UserName;danijelk -X=UserPass;ipmp -X=License;danijelk;2005-08-31;2006-08-31;ODRL -Y=isma;icm test30.mp4 enc-test30.mp4</em>.<br><br>
    Here is a sample command line for ISMA encryption on linux platform:<br>
    <em>mp4creator -E -W="EncoderInfo.xml" -X="UserName;danijelk" -X="UserPass;ipmp" -X="License;danijelk;2005-08-31;2006-08-31;ODRL" -Y="isma;icm" test30.mp4 enc-test30.mp4</em>.<br>
    
    Here is a sample command line for openIPMP encryption on windows platform:<br>
    <em>mp4creator -E -W=EncoderInfo.xml -X=UserName;danijelk -X=UserPass;ipmp -X=License;danijelk;2005-08-31;2006-08-31;ODRL -Y=openipmp;bfs test30.mp4 enc-test30.mp4</em>.<br><br>
    Here is a sample command line for openIPMP encryption on linux platform:<br>
    <em>mp4creator -E -W="EncoderInfo.xml" -X="UserName;danijelk" -X="UserPass;ipmp" -X="License;danijelk;2005-08-31;2006-08-31;ODRL" -Y="openipmp;bfs" test30.mp4 enc-test30.mp4</em>.<br><br>

    <div id="dec">
    <h2><b>mp4player with DRM support</b></h2>
    </div>
    mp4player application is used to play content. Besides standard parameters, mp4player
    now takes certain parameters needed for playing DRM protected content.<br>
    
    DRM parameters are the following:
    <ul>
    <li>-W=&lt;xml file name&gt;, [mandatory], set XML configuration file name.</li>
    <li>-X=&lt;sensitive data&gt;, set sensitive information.</li>
    </ul>
    
    XML configuration file contains necessary information for DRM decryption.<br>
    
    Sensitive information is set via command line if it shouldn't appear in the
    XML configuration file (user name, password...). -X option can be used
    multiple times. &lt;sensitive data&gt; can be:
    <ul>
    <li>UserName;&lt;user name&gt;, [mandatory, only one], user name for DRM server access.</li>
    <li>UserPass;&lt;password&gt;, [mandatory, only one], user password for DRM server access.</li>
    </ul>
        
    Sample XML configuration file for playing (windows paths must be changed to unix paths
    if playing on a linux platform): <a href="../PlayerInfo.xml">PlayerInfo</a> <br>
    
    P12FilePath tag in XML configuration file must be set to the path where .p12 file for the user identified
    with UserName and UserPass (see above) resides. See DRMPlugin documentation on how to create a user
    and get a .p12 user file.<br>
    RandomNumberFilePath tag in XML configuration file must be set to the path where entropy.dat will reside.
    Can be left as it is.<br>
    RegDatabasePath, RODatabasePath, CertPath, PrivateKeyPath, RootCAPath and TrustedCAPath tags in XML
    configuration file are used for playing OMA DRM protected content. RegDatabasePath tag and RODatabasePath
    tag must be set to registration database file path and rights database file path, respectively. If the
    given files do not exist, they will be created. These files are expected to be XML files. CertPath tag,
    PrivateKeyPath tag, RootCAPath tag and TrustedCAPath tag must be set to device certificate file path,
    device private key file path, CA certificate file path and trusted CA certificate file path. Trusted
    CA certificate is a certificate trusted by the device as a CA for server certificates. Device certificate
    file, CA certificate file and trusted CA certificate file are expected to be der encoded X509 certificate
    files. Device private key file is expected to be der encoded PKCS8 file. One can use for example openssl
    to create them.<br>
    For testing purposes, other tags in XML configuration file can be left as they are.<br>
    
    Here is a sample command line for playing protected content on windows platform:<br>
    <em>mp4player -W=PlayerInfo.xml -X=UserName;danijelk -X=UserPass;ipmp enc-test30.mp4</em><br><br>
    Here is a sample command line for playing protected content on linux platform:<br>
    <em>mp4player -W="PlayerInfo.xml" -X="UserName;danijelk" -X="UserPass;ipmp" enc-test30.mp4</em><br>
*/