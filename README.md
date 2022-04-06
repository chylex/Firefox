# About this Fork

This fork comes with preconfigured `mozconfig`, which builds Firefox Developer Edition for Windows (x64) with several build-time customizations, and patches for things that annoy me about Firefox.

The `chylex/latest` branch always represents the latest version of the fork; every time it is updated, it will be rebased on the official `beta` branch and force-pushed. The `chylex/<version>` branches contain older, immutable versions of the fork.

To include the `beta` branch from the upstream repository, use: `git remote add -t beta upstream https://github.com/mozilla/gecko-dev.git`

## Changes

* Disabled [Default Browser Agent](https://firefox-source-docs.mozilla.org/toolkit/mozapps/defaultagent/default-browser-agent/index.html)
* Disabled [Mozilla Maintenance Service](https://support.mozilla.org/en-US/kb/what-mozilla-maintenance-service)
* Disabled [Normandy](https://mozilla.github.io/normandy/dev/concepts.html) (not tested, might want to disable too `app.normandy.enabled` just in case)
* Reinstated "Open with..." option when downloading executables
* Requirement for extension signing can be disabled using `xpinstall.signatures.required`
* Allowed downgrading Firefox version without resetting your profile (use at your own risk)

## Building

The preconfigured `mozconfig` expects three API key files in the `/_keyfiles` directory. If you don't need third-party services like Google Safe Browsing, you can edit `mozconfig` and remove the lines with references to API key files. Otherwise, you can generate the API keys yourself, or extract them from an official build of Firefox.

Follow instructions for [Building Firefox on Windows](https://firefox-source-docs.mozilla.org/setup/windows_build.html), but instead of downloading the bootstrap script from official sources, it might be enough to get this fork and run `./mach bootstrap`. When the bootstrapper asks, make sure you **don't** select [Artifact Builds](https://firefox-source-docs.mozilla.org/contributing/build/artifact_builds.html).

After you build the fork with `./mach build`, read [Installer Build](https://firefox-source-docs.mozilla.org/browser/installer/windows/installer/InstallerBuild.html) to build an installer, or [Localized Builds](https://firefox-source-docs.mozilla.org/build/buildsystem/locales.html) to build an installer that includes an alternative language.

## Using

Note that the default update channel is set to `aurora`, like in official Firefox Developer Edition builds. This is for my convenience, so that I can check the "About Firefox" dialog for the current version. Obviously, you will have to **disable automatic updates** to stop Firefox from replacing your installation.

# Original README

An explanation of the Firefox Source Code Directory Structure and links to
project pages with documentation can be found at:

    https://firefox-source-docs.mozilla.org/contributing/directory_structure.html

For information on how to build Firefox from the source code and create the patch see:

    https://firefox-source-docs.mozilla.org/contributing/contribution_quickref.html

If you have a question about developing Firefox, and can't find the solution
on https://firefox-source-docs.mozilla.org/, you can try asking your question on Matrix at chat.mozilla.org in `Introduction` (https://chat.mozilla.org/#/room/#introduction:mozilla.org) channel.


Nightly development builds can be downloaded from:

    https://archive.mozilla.org/pub/firefox/nightly/latest-mozilla-central/
            - or -
    https://www.mozilla.org/firefox/channel/desktop/#nightly

Keep in mind that nightly builds, which are used by Firefox developers for
testing, may be buggy.
