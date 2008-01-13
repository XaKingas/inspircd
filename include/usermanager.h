/*       +------------------------------------+
 *       | Inspire Internet Relay Chat Daemon |
 *       +------------------------------------+
 *
 *  InspIRCd: (C) 2002-2008 InspIRCd Development Team
 * See: http://www.inspircd.org/wiki/index.php/Credits
 *
 * This program is free but copyrighted software; see
 *	    the file COPYING for details.
 *
 * ---------------------------------------------------
 */

#ifndef __USERMANAGER_H
#define __USERMANAGER_H

/** A list of ip addresses cross referenced against clone counts */
typedef std::map<irc::string, unsigned int> clonemap;

class CoreExport UserManager : public classbase
{
 private:
	InspIRCd *ServerInstance;

	/** Map of local ip addresses for clone counting
	 */
	clonemap local_clones;
 public:
	UserManager(InspIRCd *Instance)
	{
		ServerInstance = Instance;
	}

	/** Map of global ip addresses for clone counting
	 * XXX - this should be private, but m_clones depends on it currently.
	 */
	clonemap global_clones;

	/** Add a user to the local clone map
	 * @param user The user to add
	 */
	void AddLocalClone(User *user);

	/** Add a user to the global clone map
	 * @param user The user to add
	 */
	void AddGlobalClone(User *user);

	/** Remove all clone counts from the user, you should
	 * use this if you change the user's IP address 
	 * after they have registered.
	 * @param user The user to remove
	 */
	void RemoveCloneCounts(User *user);

	/** Return the number of global clones of this user
	 * @param user The user to get a count for
	 * @return The global clone count of this user
	 */
	unsigned long GlobalCloneCount(User *user);

	/** Return the number of local clones of this user
	 * @param user The user to get a count for
	 * @return The local clone count of this user
	 */
	unsigned long LocalCloneCount(User *user);




	void RemoveCloneCounts();
};

#endif
